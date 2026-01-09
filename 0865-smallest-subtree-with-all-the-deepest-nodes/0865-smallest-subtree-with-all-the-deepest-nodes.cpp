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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        //DFS
        return dfs(root).second;
    }

    //DFS
    std::pair<int, TreeNode*> dfs(TreeNode* node)
    {
        //Base Case
        if (!node)
        {
            return {0, nullptr};
        }

        //Recursive part
        std::pair<int, TreeNode*> left = dfs(node->left);
        std::pair<int, TreeNode*> right = dfs(node->right);

        if (left.first > right.first)
        {
            //Count + 1, return left..
            return {left.first + 1, left.second};
        }

        if (right.first > left.first)
        {
            //Count + 1, return right..
            return {right.first + 1, right.second};
        }
        
        //Equal
        return {left.first + 1, node};
    }

private:
    int deepestCount = -1;
};