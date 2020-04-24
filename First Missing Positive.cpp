class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        int j = -1;
        for(int i=0;i<n;i++){  //putting all numbers less than equal to 0 in front
            if(arr[i]<=0)
                swap(arr[i],arr[j+1]),j++;
        }
        if(j==(n)){ //if all are less than or equal to 0
            return 1;
        } 
        for(int i=j+1;i<n;i++){ //mark the presence of a number 
            if(abs(arr[i])<(n-j) && arr[j+abs(arr[i])]>0){
                arr[j+abs(arr[i])] *=-1; 
            }
        }
        for(int i=j+1;i<n;i++){ //first positive number index(+1) will be the missing number
            if(arr[i]>0)
                return (i-j);
        }
        return n-j;
    }
};
