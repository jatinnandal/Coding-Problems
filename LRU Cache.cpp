class LRUCache {
    list< pair<int,int> > cache;
    unordered_map<int, list< pair<int,int> >::iterator > mp;
    int capacity;
public:
    LRUCache(int c) {
        capacity = c;
    }
    int get(int key) {
        if(mp.count(key)){
            pair<int,int> p = *(mp[key]);
            cache.erase(mp[key]);
            mp.erase(key);
            cache.push_front(p);
            mp[p.first] = cache.begin();
            return p.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            cache.erase(mp[key]);
            mp.erase(key);
        }
        else if(cache.size() == capacity){
            mp.erase((cache.back()).first);
            cache.pop_back();
        }
        cache.push_front(make_pair(key,value));
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
