class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        int i=n-1;
        
        if(n==0)
            return digits;
        
        while(i>=0){
            if(digits[i] + carry == 10){
                carry = 1;
                digits[i] = 0;
                i--;
            }else{
                digits[i]+=1;
                break;
            }
        }
        
        if(i==-1)
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};
