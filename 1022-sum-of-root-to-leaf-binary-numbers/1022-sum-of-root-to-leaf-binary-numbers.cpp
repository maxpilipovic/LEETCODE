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
    int sumRootToLeaf(TreeNode* root) 
    {
        //Base Case
        if (!root)
        {
            return 0;
        }

        vector<int> curr;
        
        //Grab everything
        dfs(root, curr);

        printMatrix(res);

        int total = 0;

        for (int i = 0; i < res.size(); i++)
        {
            std::string num;
            for (int j = 0; j < res[i].size(); j++)
            {
                num += (res[i][j] + '0');
            }

            total += stoi(num, nullptr, 2);
        }

        return total;
    }

    void printMatrix(const std::vector<std::vector<int>>& matrix)
    {
        for (const auto& row : matrix)
        {
            for (int val : row)
            {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }

    void dfs(TreeNode* node, vector<int> curr)
    {

        int val = node->val;
        curr.push_back(val);

        //Check leaf
        if (!node->left && !node->right)
        {
            res.push_back(curr);
            return;
        }

        
        if (node->left)
        {
            dfs(node->left, curr);
        }
        if (node->right)
        {
            dfs(node->right, curr);
        }

    }

private:
    vector<vector<int>> res;
};