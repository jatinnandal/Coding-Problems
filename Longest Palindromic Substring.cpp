

class Solution {
public:
    string longestPalindrome(string s) {
        int max_length = 1;
        if(s.size()==1)
            return s;
        string ans;
        int start=0,end=0,str=0;
        for(int i=1;i<s.size();i++){
            start = i-1;   //considering even length palindromes
            end = i;
            while(start>=0 && end< s.size() && s[start] == s[end]){
                if(end-start+1 > max_length){
                    max_length = end-start + 1;
                    str = start;
                }
                start--;
                end++;
            }
            start = i-1;  //considering odd length palindromes with centre i
            end = i+1;
            while(start>=0 && end< s.size() && s[start] == s[end]){
                if(end-start+1 > max_length){
                    max_length = end-start + 1;
                    str = start;
                }
                start--;
                end++;
            }
             
        }
        for(int i=str;i<str+max_length;i++){
            ans+=s[i];
        }
        return ans;
    }
};
