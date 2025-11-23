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
public:
    TreeNode* lca ( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( root == nullptr || root == p || root == q ) return root;

        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        if ( left != nullptr && right != nullptr ) return root;
        return (left != nullptr) ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};
