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
    bool dfs(TreeNode* r1, TreeNode* r2) {
        if ( r1 == nullptr && r2 == nullptr ) return true;
        if ( r1 == nullptr || r2 == nullptr ) return false;

        if ( r1->val != r2->val ) return false;
        bool res1 = dfs (r1->left, r2->right);
        bool res2 = dfs (r1->right, r2->left);

        return (res1 && res2);
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};

