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
    int maxProduct(TreeNode* root) {
        //Find the sum of the subtree
        totalSum = dfs(root);
        cout << totalSum << std::endl;

        //Compute every subtree
        dfs2(root);
        return (int)(best % MOD);
    }

    long long dfs(TreeNode* start)
    {
        //Base Case
        if (!start)
        {
            return 0;
        }

        long long left = dfs(start->left);
        long long right = dfs(start->right);

        return (long long)start->val + left + right;

    }

    long long dfs2(TreeNode* start)
    {
        if (!start)
        {
            return 0;
        }

        long long left = dfs2(start->left);
        long long right = dfs2(start->right);
        long long sub = start->val + left + right;

        //This line specifically tracks the best
        best = max(best, sub * (totalSum - sub));
        
        return sub;
    }

private:
    static const int MOD = 1'000'000'007;
    int maxRes = 0;
    long long best = 0;
    long long totalSum = 0;


};