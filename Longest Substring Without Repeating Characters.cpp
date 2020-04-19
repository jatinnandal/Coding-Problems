class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int length = 0;
        int j=0;
        int max_length = 0;
        if(s==" ")
            return 1;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                max_length = max(max_length,length);
                while(mp[s[i]]>1){
                    mp[s[j]]--;
                    j++;
                    length--;
                }
                length++;
            }else{
                length++;
            }
        }
        max_length = max(length,max_length);
        return max_length;
    }
};
