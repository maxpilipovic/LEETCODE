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

        //Iterative...
        //Recursive

        if (!root)
        {
            return 0;
        }

        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push(std::make_pair(root, 1));

        while (!stack.empty())
        {

            auto [curr, count] = stack.top();
            stack.pop();

            //Check our max
            resMax = std::max(resMax, count);

            if (curr->left)
            {
                stack.push(std::make_pair(curr->left, count + 1));
            }
            if (curr->right)
            {
                stack.push(std::make_pair(curr->right, count + 1));
            }
        }

        return resMax;
    }

private:
    int resMax = 0;
};