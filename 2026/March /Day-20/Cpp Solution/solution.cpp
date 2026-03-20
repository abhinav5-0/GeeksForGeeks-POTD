/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node*ans1 = NULL;
        Node*ans2 = NULL;
        Node*temp = root;
        
        while(temp){
            if(temp->data > key)ans1=temp;
            if(temp->data <= key)temp = temp->right;
            else temp=temp->left;
        }
        
        
        temp=root;
        while(temp){
            if(temp->data < key)ans2=temp;
            if(temp->data < key)temp = temp->right;
            else temp=temp->left;
        }
        
        return {ans2,ans1};
    }
};
