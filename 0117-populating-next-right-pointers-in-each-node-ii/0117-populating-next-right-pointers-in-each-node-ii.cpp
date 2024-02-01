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
       if(root == NULL) {
           return root;
       }

       queue<Node*> leaves;
       leaves.push(root);

       while(!leaves.empty()) {
           Node* prev = NULL;
           int size = leaves.size();
           for(int i = 1; i <= size; i++) {
               Node* val = leaves.front();
               leaves.pop();

               if(prev != NULL) {
                   prev->next = val;
               }

               if(val->left != NULL) { 
                leaves.push(val->left);
               }
               if(val->right != NULL) {
                 leaves.push(val->right);  
               }

               if(i != size) {
                   prev = val;
               } else {
                   val->next = NULL;
               }
               
           }
       }

       return root;
    }
};