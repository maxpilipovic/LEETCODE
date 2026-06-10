class Solution {
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* prev = nullptr;
        dfs(root, prev);
    }

    void dfs(TreeNode* curr, TreeNode*& prev)
    {
        if (curr == nullptr)
            return;

        TreeNode* left = curr->left;
        TreeNode* right = curr->right;

        if (prev != nullptr)
        {
            prev->left = nullptr;
            prev->right = curr;
        }

        prev = curr;

        dfs(left, prev);
        dfs(right, prev);
    }
};