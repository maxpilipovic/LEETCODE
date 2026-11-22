class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int prefixSum = 0;
        int res = 0;

        for (int x : gain)
        {
            prefixSum += x;

            res = std::max(res, prefixSum);
        }    

        return res;
    }

private:

};