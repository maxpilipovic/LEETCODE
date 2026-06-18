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

    enum class Direction
    {
        Right,
        Left
    };

    int longestZigZag(TreeNode* root) 
    {
        TreeNode* curr = root;

        dfs(curr, Direction::Left, 0);
        dfs(curr, Direction::Right, 0);

        return res;
    }

    void dfs(TreeNode* curr, Direction dir, int count)
    {
        //Base Case
        if (!curr)
        {
            return;
        }

        //Check best
        if (count > res)
        {
            res = count;
        }

        //dfs part
        switch (dir)
        {
            //We are left. So go RIGHT
            case Direction::Left:
                //Continue zigzag by going right
                dfs(curr->right, Direction::Right, count + 1);

                //Reset by going left
                dfs(curr->left, Direction::Left, 1);
                break;
            //We are right. So go LEFT
            case Direction::Right:
                //Continue zigzag by going left
                dfs(curr->left, Direction::Left, count + 1);

                //Reset by going right
                dfs(curr->right, Direction::Right, 1);
                break;
        }
    }

private:
    int res = INT_MIN;
};