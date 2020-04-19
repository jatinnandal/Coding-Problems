class Solution {
    int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }
    
    int min(int a,int b){
        if(a>b)
            return b;
        else
            return a;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            if(nums1.size()>nums2.size())       //if nums2 is smaller in size swap
                return findMedianSortedArrays(nums2,nums1);
            int x = nums1.size();
            int y = nums2.size();
            int low = 0;
            int high = x;
            int xpart;       //partition in nums1
            int ypart;       //partition in nums2
            double ans = 0;
            while(low<=high){
                xpart = (low+high)/2 ;
                ypart = (x+y+1)/2 - xpart;   //xpart + ypart will be half the total numbers of elements of both                                               // the array 
                long long  l_max_x = -1000000000;
                long long r_min_x = 1000000000;
                if(xpart!=0)                   //if atleast one element is present in left partition of 1st.
                    l_max_x = nums1[xpart-1];
                if(xpart != x)
                    r_min_x = nums1[xpart];
                int l_max_y = -1000000000;
                int r_min_y = 1000000000;
                if(ypart!=0)
                    l_max_y = nums2[ypart-1];
                if(ypart != y)
                    r_min_y = nums2[ypart];
                //cout<<l_max_x<<" "<<l_max_y<<" "<<r_min_x<<" "<<r_min_y<<endl;
                
/*if last element in the left partition of 1st array is smaller than first element of right partition of 2nd array and same for the left partition of 2nd array and right partiton of 1st array then complete array will be sorted*/ 
                if(l_max_x <= r_min_y && l_max_y <=r_min_x){
                    if((x+y)%2){          //total elements are even
                        ans = max(l_max_x,l_max_y);
                        break;
                    }
                        
                    else{
                        ans = (double)((double)max(l_max_x,l_max_y) + (double)min(r_min_x,r_min_y) )/2 ;
                        break;
                    }
                }
                else if(l_max_x > r_min_y){ //move partition left
                    high = xpart-1;
                }
                else{      //move partition right
                    low = xpart+1;
                }
            }
        return ans;;
    }
};
