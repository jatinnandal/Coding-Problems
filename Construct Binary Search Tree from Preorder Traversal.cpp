/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* construct_bst(vector<int>& preorder,int s, int e ){
        if(s>e)
            return NULL;
        TreeNode* root = new TreeNode();
        root->val = preorder[s];
        root->right = root->left = NULL;
        int i = s+1;
        while(i<=e && preorder[s]>preorder[i]){
            i++;
        }
        root->left = construct_bst(preorder,s+1,i-1);
        root->right = construct_bst(preorder,i,e);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        int n = preorder.size();
        return construct_bst(preorder,0,n-1);
    }
};
