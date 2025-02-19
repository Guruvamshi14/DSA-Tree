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

    TreeNode* invertTREE(TreeNode* root) {

        if(!root)
            return NULL;
        
        
        TreeNode* le = root->left;
        TreeNode* ri = root->right;

        root->left = invertTREE(ri);
        root->right = invertTREE(le);

        return root;
    }
};