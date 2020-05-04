class Solution {
public:
    int findComplement(int num) {
        int cnt=0,temp=num;
        int ans = 0;
        while(temp>0){
            int x = (temp&1?0:1);
            if(x)
                ans|=(cnt==0?1:(1<<cnt));
            cnt++;
            temp = temp >> 1;
        }
        return ans;
    }
};
