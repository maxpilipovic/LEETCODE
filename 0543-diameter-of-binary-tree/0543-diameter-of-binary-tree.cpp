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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res = dfs(root);

        return diameter;
    }

    int dfs(TreeNode* curr)
    {
        
        //Base if curr is nothing return 0.
        if (!curr)
        {
            return 0;
        }

        int left = dfs(curr->left);
        int right = dfs(curr->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

private:
    int diameter = 0;
};