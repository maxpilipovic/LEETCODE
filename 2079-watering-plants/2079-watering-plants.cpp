class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
int bucket = capacity;

for (int i = 0; i < plants.size(); ++i)
{
    if (bucket >= plants[i])
    {
        steps += 1;
        bucket -= plants[i];
    }
    else if (bucket < plants[i])
    {
        steps += (i * 2) + 1;
        bucket = capacity - plants[i];
    }
}
return steps;
    }
};