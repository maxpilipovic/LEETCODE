class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int res = INT_MAX;

        if (nums.size() < 3)
        {
            return -1;
        }

        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] == nums[j] && nums[j] == nums[k])
                    {
                        int temp = abs(i - j) + abs(j - k) + abs(k - i);
                        res = std::min(res, temp);
                    }
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }

private:
};