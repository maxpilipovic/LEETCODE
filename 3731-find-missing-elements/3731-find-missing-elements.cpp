class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;

        unordered_set<int> hashy;

        //Find max and min
        for (int i{}; i < nums.size(); i++)
        {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);

            //Add hashy
            hashy.insert(nums[i]);
        }    

        while (minNum <= maxNum)
        {
            if (!hashy.count(minNum))
            {
                res.push_back(minNum);
            }

            minNum += 1;
        }


        return res;
    }

private:
    vector<int> res;
};