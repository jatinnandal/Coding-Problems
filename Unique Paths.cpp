class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)
            return 1;
        
        if(m==0||n==0)
            return 0;
            
        int dp[2][m];
        for(int i=0;i<m;i++)
            dp[0][i] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i%2][j] = (j>0)?(dp[(i-1)%2][j] + dp[i%2][j-1]):(dp[(i-1)%2][j]);
            }
        }
        return dp[(n-1)%2][m-1];
    }
};
