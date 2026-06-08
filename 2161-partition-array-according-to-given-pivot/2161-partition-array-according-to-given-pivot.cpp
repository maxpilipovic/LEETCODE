class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> lower;
        vector<int> higher;
        vector<int> same;

        for (size_t i{}; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                lower.push_back(nums[i]);
            }
            else if(nums[i] == pivot)
            {
                same.push_back(nums[i]);
            }
            else
            {
                higher.push_back(nums[i]);
            }
        }

        for (size_t i{}; i < lower.size(); i++)
        {
            res.push_back(lower[i]);
        }

        for (size_t i{}; i < same.size(); i++)
        {
            res.push_back(same[i]);
        }

        for (size_t i{}; i < higher.size(); i++)
        {
            res.push_back(higher[i]);
        }

        return res;
    }

private:
    vector<int> res;
};