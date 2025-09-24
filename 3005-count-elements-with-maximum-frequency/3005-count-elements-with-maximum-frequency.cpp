class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int max = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            res[nums[i]] += 1; 
        }   

        //Find our max in hashmap
        for (const auto& pair : res) 
        {
            if (pair.second > max)
            {
                max = pair.second;
            }
        }

        for (const auto& pair : res)
        {
            if (pair.second == max)
            {
                count += pair.second;
            }
        }

        return count;
    }

private:
    unordered_map<int, int> res;
};