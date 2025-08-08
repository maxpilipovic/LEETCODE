class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        size_t n = nums.size();
        std::vector<std::vector<int>> res;

        for (size_t mask = 0; mask < 1 << n; mask++)
        {
            std::vector<int> curr;
            for (size_t i = 0; i < n; i++)
            {
                //
                // -> 0001
                //1
                //2
                //mask & (1 << i)
                if (mask >> i & 1)
                {
                    curr.push_back(nums[i]);
                }
            }
            res.push_back(std::move(curr));
        }

        return res;
    }   
};