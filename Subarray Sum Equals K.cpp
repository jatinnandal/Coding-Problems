class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum-k)){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};
auto jatin = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
