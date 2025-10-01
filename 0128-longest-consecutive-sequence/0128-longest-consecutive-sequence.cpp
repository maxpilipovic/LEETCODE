class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty())
        {
            return 0;
        }

        unordered_set<int> hashy(nums.begin(), nums.end());

        for (int num : hashy)
        {

            //Beginning of a sequence...
            if (hashy.find(num - 1) == hashy.end())
            {
                int currNum = num;
                int streak = 1;

                while (hashy.find(currNum + 1) != hashy.end())
                {
                    streak += 1;
                    currNum = currNum + 1;
                }

                res = std::max(res, streak);
            }
        }

        return res;
    }

private:
    int res = 1; 
};