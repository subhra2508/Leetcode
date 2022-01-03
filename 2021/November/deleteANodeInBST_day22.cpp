
// delete A Node in the binary search tree



class Solution {
public:
    //https://www.youtube.com/watch?v=gcULXE7ViZw
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==NULL) return root;
        
        //nodes to be deleted
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else {
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
                return root;
            }
            else if(root->left == NULL){
                TreeNode*temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else if(root->right == NULL){
                TreeNode*temp = root;
                root = root->left;
                delete temp;
                return root;
                
            }
            else {
                TreeNode*temp = FindMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
                return root;
            }
        }
        return root;
    }
    TreeNode*FindMin(TreeNode*root){
        TreeNode*temp = root;
        int minel = INT_MAX;
        TreeNode*store = nullptr;
        while(temp!=NULL){
            if(temp->val < minel){
                minel = temp->val;
                store = temp;
            }
            temp = temp->left;
        }
        return store;
    }
        
};