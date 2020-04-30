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
    bool isValid(TreeNode* root, vector<int>& arr , int idx){
        if(root==NULL && idx == arr.size())
            return true;
        if(root==NULL && idx<arr.size()){
            return false;
        }
        if(root->val != arr[idx])
            return false;
        if(idx == arr.size()-1 && (root->left || root->right))
            return false;
        return isValid(root->left,arr,idx+1) || isValid(root->right,arr,idx+1);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(isValid(root,arr,0))
            return true;
        return false;
    }
};
