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
    TreeNode* insertBST(TreeNode* root, int val) {
        if ( root == nullptr ) return new TreeNode(val);

        if(root->val > val) {
            root->left = insertBST(root->left, val);
        }
        else {
            root->right = insertBST(root->right, val);
        }

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertBST(root, val);
    }
};
