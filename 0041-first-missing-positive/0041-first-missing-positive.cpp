class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_set<int> hashy;
        int n = nums.size();

        for (int i{}; i < nums.size(); i++)
        {
            hashy.insert(nums[i]);
        }    

        int count = 1;
        while (count <= n + 1)
        {
            if (!hashy.count(count))
            {
                return count;
            }
            count += 1;
        }

        return -1;
    }

private:

};