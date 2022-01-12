/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*getNewNode(int val){
        TreeNode*new_node = new TreeNode(val);
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return getNewNode(val);
        if(root->val < val){
           root->right = insertIntoBST(root->right,val); 
        }
        
        if(root->val > val){
            root->left = insertIntoBST(root->left,val);
        }
        return root;
    }
};