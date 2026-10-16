class Solution {
public:
    int maxi = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        maxi = max(maxi, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};