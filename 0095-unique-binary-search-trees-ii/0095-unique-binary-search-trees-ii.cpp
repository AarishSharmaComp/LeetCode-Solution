class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> result;

        // No nodes in this range
        if (start > end) {
            result.push_back(NULL);
            return result;
        }

        // Try every number as root
        for (int i = start; i <= end; i++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = solve(start, i - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = solve(i + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* left : leftTrees) {

                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};