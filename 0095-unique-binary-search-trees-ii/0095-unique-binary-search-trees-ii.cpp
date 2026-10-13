class Solution {
public:
    vector<TreeNode*> solve(int l, int r) {
        if (l > r) return {nullptr};

        vector<TreeNode*> ans;

        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = solve(l, i - 1);
            vector<TreeNode*> right = solve(i + 1, r);

            for (auto L : left) {
                for (auto R : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = L;
                    root->right = R;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};