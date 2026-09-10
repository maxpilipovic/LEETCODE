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
    int averageOfSubtree(TreeNode* root) 
    {
        //Recursive function.
        auto [count, sum, total] = dfs(root);

        return total;
    }

    std::tuple<int, int, int> dfs(TreeNode* node)
    {
        
        //If its an empty node return
        if (!node)
        {
            return std::tuple{0, 0, 0};
        }

        auto [count1, sum1, total1] = dfs(node->left);
        auto [count2, sum2, total2] = dfs(node->right);

        //Grab the current value
        int value = node->val;
        
        //Count of nodes seen to find average.
        int n = count1 + count2 + 1;
        int x = sum1 + sum2 + value;
        int total = total1 + total2;

        //Actually doing the sum
        if (x / n == value)
        {
            total += 1;
        }

        return {n, x, total};
    }

};