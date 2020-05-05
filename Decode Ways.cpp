class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[22];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        for(int i=3;i<=20;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        int last=0,cnt=0,ans=1;
        if(s.size()==1)
            return (s=="0")?0:1;
        if(s[0]=='0' || s.size()==0)
            return 0;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                if(s[i-1]=='0' || int(s[i-1] - '0')>2)
                    return 0;
            }
            if(s[i-1]!='0' && int(s[i-1]-'0')*10 + int(s[i]-'0') <= 26){
                if(last){
                    if(s[i]!='0')
                        cnt++;
                    else
                        cnt--;
                }else{
                    last = 1;
                    if(s[i]!='0'){
                        cnt =  1;
                    }      
                }
            }else{
                ans*=dp[cnt];
                cnt=0;
                last=0;
            }
        }
        if(cnt){
            ans*=dp[cnt];
        }
        return ans;
    }
};
