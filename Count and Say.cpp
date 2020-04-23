class Solution {
public:
    string countAndSay(int n) {
        string arr[31];
        arr[1] = "1";
        arr[2] = "11";
        for(int i=3;i<=n;i++){
            string s;
            int count=1;
            bool f=0;
            string str = arr[i-1];
            for(int j=1;j<str.size();j++){
                if(str[j]==str[j-1]){
                    f=1;
                    count++;
                }else{
                    char c = count + '0';
                    s.push_back(c);
                    char a = str[j-1];
                    s.push_back(a);
                    count=1;
                    f=0;
                }
            }
            if(f){
                char c = count + '0';
                s.push_back(c);
                char a = str[str.size()-1];
                s.push_back(a); 
            }else{
               s.push_back('1');
               s.push_back(str[str.size()-1]);
            }
            arr[i] = s;
        }
        return arr[n];
    }
};
