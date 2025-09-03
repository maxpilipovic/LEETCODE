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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if (nums.empty())
        {
            return nullptr;
        }

        TreeNode* res = build(0, nums.size() - 1, nums);

        return res;
    }

    TreeNode* build(int l, int r, vector<int>& nums)
    {

        //Base Case
        if (l > r)
        {
            return nullptr;
        }
        //Take midpoint
        int mid = l + (r - l) / 2;
        
        //Create new node wit value
        TreeNode* curr = new TreeNode(nums[mid]);

        //Recursively connstruct right & left subtree
        curr->left = build(l, mid - 1, nums);
        curr->right = build(mid + 1, r, nums);

        return curr;
    }
};