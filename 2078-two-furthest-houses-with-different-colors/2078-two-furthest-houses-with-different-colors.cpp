class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        
        for (int i = 0; i < colors.size(); i++)
        {
            for (int j = i + 1; j < colors.size(); j++)
            {
                if (colors[i] != colors[j])
                {
                    int dist = abs(i - j);
                    res = max(res, dist);

                }
            }
        }

        return res;
    }

private:
    int res = INT_MIN;
};