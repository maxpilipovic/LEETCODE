class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int64_t res = 0;

for (int i = 0; i < nums.size(); ++i)
{
    int minVal = nums[i];
    int maxVal = nums[i];
    for (int j = i; j < nums.size(); ++j)
    {   
        minVal= std::min(minVal, nums[j]);
        maxVal = std::max(maxVal, nums[j]);
        
        
        res += (maxVal - minVal);
    }
}
return res; // TODO: check return type
    }
};