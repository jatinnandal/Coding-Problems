class FirstUnique {
    list<int> l;
    unordered_map<int , list<int> :: iterator > mp;
public:
    FirstUnique(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.count(nums[i]) && mp[nums[i]]!=l.end()){
                l.erase(mp[nums[i]]);
                mp[nums[i]] = l.end();
            }else if(!(mp.count(nums[i]))){
                l.push_back(nums[i]);
                list<int> :: iterator it;
                it = l.end();
                if(!l.empty()){
                    it--;
                    mp[nums[i]] = it;
                }else{
                    mp[nums[i]] = l.begin();
                }
                
            }
        }
    }
    
    int showFirstUnique() {
        if(l.size())
            return l.front();
        else
            return -1;
    }
    
    void add(int value) {
        if(mp.count(value) && mp[value]!=l.end()){
            list<int> :: iterator it;
            l.erase(mp[value]);
            mp[value]=l.end();
        }else if(!(mp.count(value))){
            l.push_back(value);
            list<int> :: iterator it;
            it = l.end();
            if(!l.empty()){
                it--;
                mp[value] = it;
            }else{
                mp[value] = l.begin();
            }
        }
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
