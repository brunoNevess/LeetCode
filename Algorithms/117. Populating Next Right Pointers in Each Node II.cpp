/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* ant = q.front();q.pop();
            if(ant->left) q.push(ant->left);
            if(ant->right) q.push(ant->right);
            Node* prox;
            for(int i=0;i<n;i++){
                if (i==n-1) ant->next = NULL;
                else{
                    prox = q.front();q.pop();
                    if(prox->left) q.push(prox->left);
                     if(prox->right) q.push(prox->right);
                    ant->next = prox;
                    ant = prox;
                }
            }
            
        }
        return root;
    }
};