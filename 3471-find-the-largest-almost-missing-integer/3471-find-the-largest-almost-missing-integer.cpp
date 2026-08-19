class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int left = 0;
        unordered_map<int, int> map;
        unordered_map<int, int> res;

        for (int right{}; right < nums.size(); right++)
        {
            map[nums[right]] += 1;

            //Window is k size
            while (right - left + 1 >= k)
            {

                //Gather the ones in the unordered_map
                FindValues(map, res);

                map[nums[left]] -= 1;

                if (map[nums[left]] == 0)
                {
                    map.erase(nums[left]);
                }
                
                //Increase pointer
                left += 1;
            }
        }

        int ans = -1;

        //Find most min val
        for (auto& [key, val] : res)
        {
            if (val == 1)
            {
                ans = max(ans, key);
            }
        }

        return ans;
    }

    void FindValues(unordered_map<int, int>& map, unordered_map<int, int>& res)
    {
        //Add all the keys to map.
        for (auto& [key, val] : map)
        {
            res[key] += 1;
        }
    }

private:

};