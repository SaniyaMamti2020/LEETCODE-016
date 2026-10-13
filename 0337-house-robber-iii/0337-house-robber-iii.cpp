class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int rob = root->val + l.second + r.second;
        int skip = max(l.first, l.second) + max(r.first, r.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};