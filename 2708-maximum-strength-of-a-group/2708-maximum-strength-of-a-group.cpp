class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        std::vector<int> positives;
std::vector<int> negatives;
int zeroCount = 0;

for (int i = 0; i < nums.size(); ++i)
{
    if (nums[i] > 0)
    {
        positives.push_back(nums[i]);
    }

    if (nums[i] < 0)
    {
        negatives.push_back(nums[i]);
    }
    if (nums[i] == 0)
    {
        zeroCount++;
    }
}

//Sort
std::sort(negatives.begin(), negatives.end());

//Edge Cases
if (positives.empty() && negatives.size() < 2)
{
    return *max_element(nums.begin(), nums.end());
}

if (negatives.size() % 2 == 1)
{
    negatives.pop_back();
}

long long product = 1;

//Loop
for (int i = 0; i < positives.size(); ++i)
{
    product *= positives[i];
}

for (int i = 0; i < negatives.size(); ++i)
{
    product *= negatives[i];
}

return product;
    }
};