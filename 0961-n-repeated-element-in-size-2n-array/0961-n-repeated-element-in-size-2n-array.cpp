class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n = nums.size() / 2;

        for (int i = 0; i < nums.size(); i++)
        {
            hashy[nums[i]]++;
        }

        for (auto [key, value] : hashy)
        {
            if (value == n)
            {
                return key;
            }
        }

        return 0;

    }

private:
    unordered_map<int, int> hashy;
};