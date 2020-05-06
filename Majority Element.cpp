class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int ans=0,cnt=0;
        for(int n: nums){
            if(cnt==0){
                ans = n;
            }
            if(n==ans){
                cnt++;
            }else{
                cnt--;
            }
        }
        return ans;
    }
};
