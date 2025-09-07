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
#include <queue>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root)
        {
            return res;
        }

        bfs(root);

        return res;
    }

    void bfs(TreeNode* root)
    {
        myQueue.push(root);

        while (!myQueue.empty()) 
        {
            
            int n = myQueue.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode* top = myQueue.front();
                myQueue.pop();

                if (i == n - 1) //Rightmost value
                {
                    res.push_back(top->val);
                }

                //Add left and right child
                if (top->left)
                {
                    myQueue.push(top->left);
                }

                if (top->right)
                {
                    myQueue.push(top->right);
                }
            }
        }

    }   

private:
    vector<int> res;
    std::queue<TreeNode*> myQueue;


};