class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        int maxNum = INT_MIN;
        unordered_set<int> hashy;

        for (int i{}; i < nums.size(); i++)
        {
            maxNum = std::max(nums[i], maxNum);
            hashy.insert(nums[i]);
            
        }

        int count = 1;

        while (count)
        {
            if (count % k == 0 && !hashy.count(count))
            {
                res = count;
                break;
            }

            count += 1;
        }

        return res;
    }

private:
    int res = INT_MAX;
};