/*
f(0): ""

f(1): "("f(0)")"

f(2): "("f(0)")"f(1), "("f(1)")"

f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"

So f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > dp(n+1);
        dp[0] = vector<string>{""};
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                for(string s: dp[j]){
                    for(string t: dp[i-j-1]){
                        string q =  "(" + s + ")" + t;
                        dp[i].push_back(q);
                    }
                }
            }
        }
        return dp[n];
    }
};
