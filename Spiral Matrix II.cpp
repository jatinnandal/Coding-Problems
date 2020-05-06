class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0 , r2 = n-1;
        int c1 = 0,  c2 = n-1;
        vector<vector<int> > v;
        int arr[n][n];
        int cnt = 1;
        while(r1<=r2 && c1<=c2){
            for(int c = c1;c<=c2;c++){
                arr[r1][c] = cnt;
                cnt++;
            }
            for(int r = (r1+1);r<=r2;r++){
                arr[r][c2] = cnt;
                cnt++;
            }
            if(r1<r2 && c1<c2){
                for(int c = c2-1;c>c1;c--){
                    arr[r2][c] = cnt;
                    cnt++;
                }
                for(int r = r2;r>r1;r--){
                    arr[r][c1] = cnt;
                    cnt++;
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        for(int i=0;i<n;i++){
            vector<int> _v;
            for(int j=0;j<n;j++){
                _v.push_back(arr[i][j]);
            }
            v.push_back(_v);
        }
        return v;
    }
};
