class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
         int aliceBucket = capacityA;
int bobBucket = capacityB;
int i = 0;
int j = plants.size() - 1;
int total = 0;

while (i <= j)
{   

    if (i == j)
    {

        if (std::max(aliceBucket, bobBucket) < plants[i])
        {
            total += 1;
            break;
        }
    }

    if (aliceBucket >= plants[i])
    {
        aliceBucket -= plants[i];
    }
    else
    {
        aliceBucket = capacityA;
        aliceBucket -= plants[i];
        total += 1;
    }

    if (bobBucket >= plants[j])
    {
        bobBucket -= plants[j];
    }
    else
    {
        bobBucket = capacityB;
        bobBucket -= plants[j];
        total += 1;
    }
    i++;
    j--;
}


return total;
    }
};