class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        vector<long long> res(nums.size(), 0); 
        
        //Group all elements into hashy
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]].push_back(i);
        }

        for (auto& [value, indices] : map)
        {
            int n = indices.size();
            vector<long long> prefix(n, 0);
            prefix[0] = indices[0];

            for (int i = 1; i < n; i++)
            {
                prefix[i] = prefix[i - 1] + indices[i];
            }

            for (int i = 0; i < n; i++)
            {
                long long idx = indices[i];

                //Grab left
                long long leftSum = (i > 0) ? prefix[i - 1] : 0;
                long long leftCount = i;
                long long left = leftCount * idx - leftSum;

                //Grab right
                long long rightSum = prefix[n - 1] - prefix[i];
                long long rightCount = n - i - 1;
                long long right = rightSum - rightCount * idx;

                res[idx] = left + right;
            }
        }

        return res;
    }

private:
    unordered_map<int, vector<int>> map;
};