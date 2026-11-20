class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        unordered_map<int, int> map;

        for (int i{}; i < nums.size(); i++)
        {
            int curr = nums[i];

            int need = target - curr;

            auto it = map.find(need);

            if (it != map.end())
            {
                return { it->second, i };
            }

            map[nums[i]] = i;
        }    

        return {};
    }

private:

};