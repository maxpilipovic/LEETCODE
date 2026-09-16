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
    int goodNodes(TreeNode* root) 
    {
        int x = root->val;
        return dfs(root, x);
    }

    int dfs(TreeNode* node, int maxVal)
    {
        if (!node)
        {
            return 0;
        }

        int count = (node->val >= maxVal) ? 1 : 0;

        int newMax = std::max(maxVal, node->val);

        int left = dfs(node->left, newMax);
        int right = dfs(node->right, newMax);

        return count + left + right;
    }
};