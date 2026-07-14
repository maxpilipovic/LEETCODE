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

        dfs(root);

        return diameter;
    }

    int dfs(TreeNode* root)
    {
        TreeNode* curr = root;

        //If curr null, return 0.
        if (!curr)
        {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

private:
    int diameter = 0;
};