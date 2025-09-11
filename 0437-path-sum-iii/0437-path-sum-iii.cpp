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
    int pathSum(TreeNode* root, int targetSum) {
        
        //Recursive DFS
        traverse(root, targetSum);
        
        return res;
        
    }

    void dfs(TreeNode* curr, int targetSum, long long count)
    {
        if (!curr)
        {
            return;
        }

        count += curr->val;

        //Base Case
        if (count == targetSum)
        {
            res += 1;
        }

        if (curr->left)
        {
            dfs(curr->left, targetSum, count);
        } 

        if (curr->right)
        {
            dfs(curr->right, targetSum, count);
        }


    }

    void traverse(TreeNode* root, int targetSum)
    {
        if (!root)
        {
            return;
        }

        dfs(root, targetSum, 0);

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);
    }

private:

    int res = 0;

};