class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {

        //This should be done with left + right - 1 to grab window size. Not a vector
        unordered_map<int, int> x;
        int left = 0;
        vector<int> res;
        
        for (int right{}; right < nums.size(); right++)
        {
            x[nums[right]] += 1;
            res.push_back(nums[right]);

            while (x[nums[right]] > k)
            {
                //remove from hashy
                x[nums[left]] -= 1;

                //If its zero, erase.
                if (x[nums[left]] == 0)
                {
                    x.erase(nums[left]);
                }

                //Increase left by 1
                left += 1;

                //Remove first element
                res.erase(res.begin());
            }

            //Grab the size and update it.
            size = std::max(size, static_cast<int>(res.size()));
        }    

        return size;
    }

private:
    int size = INT_MIN;
};