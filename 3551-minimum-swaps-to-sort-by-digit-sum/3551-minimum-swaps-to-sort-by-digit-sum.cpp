class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        //Make digit sum
        int n = nums.size();
        vector<pair<int, int>> res(n);
        unordered_map<int, int> map;

        int swaps = 0;

        //Array of pairs to keep track of og and digitsum
        for (int i{}; i < nums.size(); i++)
        {
            res[i] = { DigitSum(nums[i]), nums[i] };
        }

        //Sort
        std::sort(res.begin(), res.end());

        //Point where the value goes using og number (nums[i])
        for (int i{}; i < n; i++)
        {
            map[res[i].second] = i;
        }

        vector<bool> visited(n, false);

        //Count the swaps
        for (int i{}; i < n; i++)
        {
            while (map[nums[i]] != i)              //wrong number in this chair?
            {
                int target = map[nums[i]];         //where it belongs
                std::swap(nums[i], nums[target]);  //send it home
                swaps++;
            }
        }

        return swaps;
    }

    int DigitSum(int s)
    {
        int num = 0;

        while (s > 0)
        {
            int last = s % 10;
            num += last;
            s /= 10;
        }

        return num;
    }
private:

};