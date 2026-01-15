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
    int countNodes(TreeNode* root) 
    {
        
        //Base Case... If its empty?

        if (!root)
        {
            return 0;
        }

        int res = 0;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int n = queue.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode* node = queue.front();
                int val = node->val;
                queue.pop();

                res++;

                if (node->left)
                {
                    queue.push(node->left);
                }

                if (node->right)
                {
                    queue.push(node->right);
                }
            }
        }

        return res;
    }

private:
    int res2 = 0;
};