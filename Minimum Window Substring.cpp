class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()==0 || t.length()==0 || s.length()<t.length())
            return "";
        int l = 0,r=0;
        unordered_map<char,int> mp;
        unordered_map<char,int> wmp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int dist = mp.size();
        int count=0,bgn=0,len=0;
        while(r<s.size()){
            wmp[s[r]]++;
            if(wmp[s[r]]==mp[s[r]]){
                count++;
            }
            while(l<=r && count == dist){
                wmp[s[l]]--;
                if(mp.count(s[l]) && wmp[s[l]] < mp[s[l]]){
                    count--;
                    if(len>(r-l+1) || len == 0){
                        len = r-l+1;
                        bgn = l;
                    }
                }
                    
                l++;
            }
            r++;
        }
        return s.substr(bgn,len);
    }
};
