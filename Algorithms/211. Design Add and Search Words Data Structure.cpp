
class Trie {
public:
    /** Initialize your data structure here. */
    const static int SIZE = 26;
    struct Node{
        Node* children[SIZE];
        bool isLeaf;
        Node(){
            for(int i = 0;i<SIZE;i++){
                children[i] = nullptr;
            }
            isLeaf = false;
        }
    };
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
        p->isLeaf = true;
        
    }
    /** Returns if the word is in the trie. */
    bool search(string word,Node* root) {
         
        Node* p = root;
        for(int i=0;i<word.size();i++){
            if(word[i] == '.'){
                for(int j=0;j<SIZE;j++){
                    if(p->children[j]){
                        if(search(word.substr(i+1),p->children[j])) return true;
                    }
                }   
                return false;
            }
            else{
                int index = word[i] - 'a';
                if(!p->children[index]) return false;
                p = p->children[index];
            }
        }
        return p!=nullptr and p->isLeaf == true;
    }
    
  
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* t;
    WordDictionary() {
        t = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        t->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return t->search(word,t->root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */