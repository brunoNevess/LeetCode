const int SIZE = 26;

struct Node{
    Node* children[SIZE];
    bool isWord;
    Node(){
        for(int i = 0;i<SIZE;i++){
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    
    Node* root;
    Trie() {
        root = new Node();
        
    }
    
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(!p->children[index]){
                p->children[index] = new Node();
            }
            p = p->children[index];
        }
        p->isWord = true;
        
    }
    
    /** Returns if the word is in the trie. */
    
    
    
    bool search(string word) {
         
        Node* p = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(!p->children[index]) return false;
            p = p->children[index];
        }
        return p!=nullptr and p->isWord == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Node* p = root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if(!p->children[index]) return false;
            p = p->children[index];
        }
        return p!=nullptr;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */