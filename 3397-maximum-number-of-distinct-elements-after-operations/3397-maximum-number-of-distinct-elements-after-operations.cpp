class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        //Greedy approach
        std::sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            long long left = (long long)nums[i] - k;
            long long right = (long long)nums[i] + k;

            long long pick = max(left, last + 1);

            if (pick <= right)
            {
                res.insert(pick);
                last = pick;
            }
            
        }

        return res.size();
    }

private:
    std::set<int> res;
};