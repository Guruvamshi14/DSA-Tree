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
    bool findSubRoot(TreeNode* root, TreeNode* subRoot){

        if(!root) return NULL;

        bool ans = false;
        if(root->val == subRoot->val){
            ans = checkEqual(root,subRoot);
        }

        bool left = findSubRoot(root->left,subRoot);
        bool right = findSubRoot(root->right,subRoot);

        return left || right || ans;
    }

    bool checkEqual(TreeNode* root, TreeNode* subRoot){

        if(!root && !subRoot) return true;
        if(!root) return false;
        if(!subRoot) return false;

        if(root->val != subRoot->val) return false;

        bool left = checkEqual(root->left,subRoot->left);
        bool right = checkEqual(root->right,subRoot->right);

        return left&&right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return findSubRoot(root,subRoot);
    }
};