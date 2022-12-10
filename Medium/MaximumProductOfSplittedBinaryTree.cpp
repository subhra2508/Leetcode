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
     long int dfs(TreeNode* root,long int &ans){
        if(!root){
            return 0;
        }
        long int sum=root->val+dfs(root->left,ans)+dfs(root->right,ans);
        if((total-sum)*sum>ans){
            ans=(total-sum)*sum;
        }
        return sum;
    }
 */
class Solution {
public:
long int total = 0;
 long int maxSum = 0;
    int maxProduct(TreeNode* root) {
        sumTree(root);
        dfs(root,maxSum);
        return maxSum%1000000007;
    }
    void sumTree(TreeNode*root){
        if(!root)return ;
        sumTree(root->left);
        total+=root->val;
        sumTree(root->right);
    }
   long int dfs(TreeNode*root,long int &maxSum){
       if(!root)return 0;
       //subtree sum
       long int sum = root->val+dfs(root->left,maxSum)+dfs(root->right,maxSum);
       //finding the max
       if(( total-sum)*sum > maxSum){
           maxSum = (total-sum)*sum;
       }
       //returning the value for the upper subtree to form
       return sum;
   } 
};