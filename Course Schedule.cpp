class Solution {
    bool DFS(list<int> adj[],int node,int color[],int n){
        color[node] = 1;
        list<int>::iterator i;
        for(i=adj[node].begin();i!=adj[node].end();i++){
            if(color[*i] == 1)
                return true;
            if(color[*i] == 0 && DFS(adj,*i,color,n) )
                return true;
        }
        color[node] = 2;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        int color[n];
        list<int> adj[n];
        for(int i=0;i<p.size();i++){
            for(int j=1;j<p[i].size();j++){
                adj[p[i][0]].push_back(p[i][j]);
            }
        }
        for(int i=0;i<n;i++)
            color[i] = 0;
        for(int i=0;i<n;i++){
                if(color[i]==0 && DFS(adj,i,color,n))
                    return false;
        }
        return true;
    }
};
