class Solution {
public:
    bool static compare(string a, string b){
            return (a+b)>(b+a);
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int n:nums){
            v.push_back(to_string(n));
        }
        string ans = "";
        sort(v.begin(),v.end(),compare);
        if(v[0] == "0")
            return "0";
        for(auto s: v){
            ans+=s;
        }
        return ans;
        
    }
};
