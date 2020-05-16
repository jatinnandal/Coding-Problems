class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxm = INT_MIN;
        bool f=0;
        for(int num:A){
            if(num>0){
                f=1;
                break;
            }
            maxm = max(maxm,num);
        }
        if(!f){
            return maxm;
        }
        int maxm1=INT_MIN;
        int sum = 0;
        for(int num: A){
            sum+=num;
            if(sum>maxm1)
                maxm1 = sum;
            if(sum<0)
                sum=0;
        }
        int maxm2=INT_MIN;
        int total_sum=0;
        sum=0;
        for(int i=0;i<A.size();i++){
            total_sum+=A[i];
            A[i] = -A[i];
        }
        for(int num: A){
            sum+=num;
            if(sum>maxm2)
                maxm2 = sum;
            if(sum<0)
                sum=0;
        }
        cout<<maxm2<<endl;
        maxm2+=total_sum;
        return max(maxm1,maxm2);
        
    }
};
