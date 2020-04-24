class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)
            return 0;
        int left[n+1];
        int right[n+1];
        left[0] = 0;
        right[n-1] = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i-1]);
        }
        for(int i = (n-2);i>=0;i--){
            right[i] = max(right[i+1],height[i+1]);
        }
        for(int i=0;i<n;i++){
            if(height[i]<left[i] && height[i]<right[i]){
                ans+=(min(right[i],left[i])-height[i]);
            }
        }
        return ans;
    }
};
