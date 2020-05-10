class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int inc[N+1];           //number of incoming edges
        int out[N+1];           // number of outgoing edges
        memset(inc, 0, sizeof(inc));
        memset(out, 0, sizeof(out));
        for(int i=0;i<trust.size();i++){
            inc[trust[i][1]]++;
            out[trust[i][0]]++;
        }
        for(int i=1;i<=N;i++){
            if(inc[i]==(N-1)&&out[i]==0)
                return i;
        }
        return -1;
    }
};
