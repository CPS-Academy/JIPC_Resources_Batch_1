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
    bool check(TreeNode* root, TreeNode* low, TreeNode* high) {
        if(root == nullptr) return true;

        if( low != nullptr && root->val <= low->val ) return false;
        if( high != nullptr && root->val >= high->val ) return false;

        bool left = check(root->left, low, root );
        bool right = check(root->right, root, high);

        return (left && right);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, nullptr, nullptr);
    }
};
