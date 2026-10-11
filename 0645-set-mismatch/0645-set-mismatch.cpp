class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        unordered_set<int> hashy2;
        unordered_set<int> hashy;
        int n = nums.size();

        for (int i = 1; i <= n; i++)
        {
            hashy2.insert(i);
        }

        for (int i{}; i < nums.size(); i++)
        {
            if (hashy.count(nums[i]))
            {
                res.push_back(nums[i]);
            }

            if (hashy2.count(nums[i]))
            {
                hashy2.erase(nums[i]);
            }

            hashy.insert(nums[i]);
        }    

        //Last loop through hashy2
        for (auto it = hashy2.begin(); it != hashy2.end(); ++it) 
        {
            res.push_back(*it);
        }

        return res;
    }

private:
    vector<int> res;
};