class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2,nums.size());
        vector<vector<int> > v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums.size();j++){
                if( (i & (1<<j) )!=0){
                    v[i].push_back(nums[j]);
                }
            }
        }
        return v;
    }
};
