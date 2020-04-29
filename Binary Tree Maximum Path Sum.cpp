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
    int ans;
    int maxSum(TreeNode* root){
        if(root==NULL)
            return 0;
        int left_max = maxSum(root->left); // max sum in left subtree
        int right_max = maxSum(root->right); // max sum in right subtree
        int include_prev = max(root->val,root->val + max(left_max,right_max)); // include only one child of                                                                                     //current node 
        ans = max(ans,max(include_prev,(left_max+right_max+root->val))); // max of starting new path at current node 
        return include_prev;                                    // and including current node in previous node
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxSum(root);
        return ans;
    }
};
