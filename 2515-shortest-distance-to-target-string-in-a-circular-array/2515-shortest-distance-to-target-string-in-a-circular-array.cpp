class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) 
    {
        int n = words.size();
        int lastIndex = words.size() - 1;
        int res = INT_MAX;

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == target)
            {
                int dist = abs(i - startIndex);
                int circularDist = min(dist, (n - dist));
                res = min(res, circularDist);
            }
        }

        if (res == INT_MAX)
        {
            return -1;
        }

        return res;
    }
};