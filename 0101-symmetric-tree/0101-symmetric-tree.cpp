class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both nodes are NULL
        if (left == NULL && right == NULL)
            return true;

        // One is NULL, the other isn't
        if (left == NULL || right == NULL)
            return false;

        // Values don't match
        if (left->val != right->val)
            return false;

        // Check mirror sides
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};