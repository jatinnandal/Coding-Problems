class Trie {
public:
    /** Initialize your data structure here. */
    Trie* children[26];
    bool end;
    Trie() {
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(int i=0;i<word.length();i++){
            if(root->children[word[i]-'a']==NULL){
                root->children[word[i]-'a'] = new Trie();
            }
            root = root->children[word[i]-'a'];
        }
        root->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(int i=0;i<word.size();i++){
            if(root->children[word[i]-'a']==NULL)
                return false;
            root = root->children[word[i]-'a'];
        }
        if(!root || !(root->end))
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(int i=0;i<prefix.length();i++){
            if(root->children[prefix[i]-'a'] == NULL)
                return false;
            root = root->children[prefix[i]-'a'];
        }
        if(root)
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
