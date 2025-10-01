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
#include <stack> 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if (!root)
        {
            return 0;
        }

        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});

        while (!stack.empty())
        {

            auto [node, count] = stack.top();
            stack.pop();

            if (node->left)
            {
                stack.push({node->left, count + 1});
            }

            if (node->right)
            {
                stack.push({node->right, count + 1});
            }

            if (count > res)
            {
                res = count;
            }
        }

        return res;

    }
private:
    int res = 0;
};