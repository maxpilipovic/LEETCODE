class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        unordered_map<int, vector<int>> pos;

        //Group all elements by index
        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]].push_back(i);
        }

        for (auto& [x, v] : pos)
        {
            for (int i = 2; i < v.size(); i++)
            {
                ans = min(ans, 2 * (v[i] - v[i - 2]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

private:
    int ans = INT_MAX;
};