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
    int dfs(TreeNode* root, int &ans) {
        if ( root == nullptr ) return 0;

        int leftDepth = dfs(root->left, ans);
        int rightDepth = dfs(root->right, ans);

        ans = max ( ans, leftDepth + rightDepth + 1 );

        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans-1;
    }
};
