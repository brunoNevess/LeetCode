/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        Node* ret = new Node(1);
        Node* prev = ret;
        q.push(node);
        unordered_set<int> visited;
        visited.insert(1);
        unordered_map<int,Node*> m;
     //   unordered_map<int,vector<Node*
        m[1] = ret;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(Node* x:p->neighbors){
                if(visited.find(x->val)==visited.end()){
                    visited.insert(x->val);
                    q.push(x);
                    Node* xx = new Node(x->val);
                    m[x->val] = xx;
                    m[p->val]->neighbors.push_back(xx);
                }
                else{
                    m[p->val]->neighbors.push_back(m[x->val]);
                }
            }
        }
        return ret;
        
    }
};