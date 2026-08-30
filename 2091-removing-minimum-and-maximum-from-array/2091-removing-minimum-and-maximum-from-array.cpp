class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        std::pair<int, int> minVal = {INT_MAX, -1};
        std::pair<int, int> maxVal = {INT_MIN, -1};

        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] < minVal.first)
            {
                minVal.first = nums[i];
                minVal.second = i;
            }

            if (nums[i] > maxVal.first)
            {
                maxVal.first = nums[i];
                maxVal.second = i;
            }
        }   

        int lo = min(minVal.second, maxVal.second);
        int high = max(minVal.second, maxVal.second); 

        int popFromFront = high + 1;
        int popFromBack  = n - lo;
        int popFromBoth  = (lo + 1) + (n - high);

        return std::min({popFromFront, popFromBack, popFromBoth});
    }
};