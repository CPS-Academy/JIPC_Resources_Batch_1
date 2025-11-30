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
    int successor(TreeNode* root) {
        root = root->right;
        while ( root->left != nullptr ) root = root->left;
        return root->val;
    }

    int precedor(TreeNode* root) {
        root = root->left;
        while ( root->right != nullptr ) root = root->right;
        return root->val;
    }

    TreeNode* del ( TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val > key) root->left = del(root->left, key);
        else if(root->val < key) root->right = del(root->right, key);
        else {
            if ( root->right != nullptr ) {
                root->val = successor(root);
                root->right = del(root->right, root->val);
            }
            else if(root->left != nullptr) {
                root->val = precedor(root);
                root->left = del(root->left, root->val);
            }
            else root = nullptr;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root, key);
    }
};

