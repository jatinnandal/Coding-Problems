class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=m;
        if(m==0)
            return 0;
        else if(m==n)
            return m;
        else if(pow(2,int(log2(n)))>m && pow(2,int(log2(n)))<=n){ //if a power of 2 is between m and n then                     return 0;                                          //answer wiil be 0 as MSB of both m and n will            }                                                        //be different.                                    
        else{
            for(int i=m+1;i<n;i++){
                ans = ans&i;
            }   
        }
        return ans&n;
    }
};
