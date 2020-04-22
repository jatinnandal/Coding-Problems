class Solution {
    int find_index(vector<int>& nums, int target,bool f){
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target){
                if( f?(mid!=e && nums[mid+1]==target):(mid!=s && nums[mid-1]==target)){
                    f?(s = mid+1):e=mid-1;
                }else{
                    return mid;
                }
            }else{
                if(nums[mid]>target){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int s = 0;
        int e = nums.size()-1;
        v.push_back(-1);
        v.push_back(-1);
        
        v[0] = find_index(nums,target,false);
        if(v[0]==-1)
            return v;
        v[1] = find_index(nums,target,true);
        return v;
    }
};
