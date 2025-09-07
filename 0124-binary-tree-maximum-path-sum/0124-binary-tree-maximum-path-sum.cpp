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
    int maxPathSum(TreeNode* root) 
    {
        
        if (!root) return 0;

        dfs(root);

        return maxRes;
    }

    int dfs(TreeNode* node)
    {

        //Base Case
        if (!node)
        {
            return 0;
        }

        int leftVal = std::max(0, dfs(node->left));
        int rightVal = std::max(0, dfs(node-> right));

        int currMax = node->val + leftVal + rightVal;

        //Check our max
        maxRes = std::max(maxRes, currMax);

        return node->val + std::max(leftVal, rightVal);
    }

private:

    int maxRes = INT_MIN; //global variable to return...
};