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
    int maxLevelSum(TreeNode* root) {

        std::queue<TreeNode*> queue;
        int level = 0;
        queue.push(root);

        while (!queue.empty())
        {
            int n = queue.size();
            int count = 0;
            level += 1;

            for (int i = 0; i < n; i++)
            {
                TreeNode* val = queue.front();
                queue.pop();

                //Add to count
                count += val->val;
                
                if (val->left)
                {
                    queue.push(val->left);
                }

                if (val->right)
                {
                    queue.push(val->right);
                }
            }

            if (count > res)
            {
                res = count;
                resLevel = level; 
            }
        }

        return resLevel;
    }

private:
    int res = INT_MIN;
    int resLevel = INT_MIN;
};