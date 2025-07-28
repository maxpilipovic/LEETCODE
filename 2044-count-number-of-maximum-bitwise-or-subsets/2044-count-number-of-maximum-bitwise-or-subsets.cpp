class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //Ethan goated solution, not me
        
        int maxOr = 0;
//Gets our max num
for (int num : nums)
{
    maxOr |= num;
}

int count = 0;

for (int i = 1; i < (1 << nums.size()); ++i)
{
    int currOr = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (i & (1 << j))
        {
            currOr |= nums[j];
        }
    }

    if (currOr == maxOr)
    {
        count++;
    }

}

return count;
    }
};