class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        int n = cost.size();
        sort(cost.begin(), cost.end());

        for (int i = n - 1; i >= 0; i -= 3)
        {
            if (i - 2 >= 0)
            {
                int x = cost[i];
                int x1 = cost[i - 1];
                int free = cost[i - 2];

                res += x;
                res += x1;
            }
            else if (i - 1 >= 0)
            {
                int x = cost[i];
                int x1 = cost[i - 1];

                res += x;
                res += x1;
            }
            else
            {
                int x = cost[i];

                res += x;
            }
        }

        return res;
    }

private:
    int res = 0;
};