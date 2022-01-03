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
    
    pair<int,int>max_robbed_house(TreeNode*root){
        if(root==NULL)return {0,0};
        
        
        pair<int,int>left = max_robbed_house(root->left);
        pair<int,int>right = max_robbed_house(root->right);
        
        //left.second is when left child is not included
        //right.second is when right child not included
        int root_house_robbed = left.second+right.second+root->val;
        int root_house_not_robbed = max(left.first,left.second)+max(right.first,right.second);
        pair<int,int>ans;
        ans.first = root_house_robbed;
        ans.second = root_house_not_robbed;
        return ans;
    }
    
    
    int rob(TreeNode* root) {
        pair<int,int>result = max_robbed_house(root);
        return max(result.first,result.second);
    }
};