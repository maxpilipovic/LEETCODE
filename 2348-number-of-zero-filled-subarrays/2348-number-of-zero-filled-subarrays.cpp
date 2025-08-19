class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        //Sliding Window
        size_t left = 0;
        long long count = 0;
        int streak = 0;

        for (int num : nums)
        {
            if (num == 0)
            {
                streak += 1;
                count += streak;
            }
            else 
            {
                streak = 0;
            }
        }

        return count;


    }

private:
    std::unordered_map<int, int> my_dict;

};