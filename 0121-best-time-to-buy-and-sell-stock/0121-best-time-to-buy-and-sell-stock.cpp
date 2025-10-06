class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        for (int i = 0; i < prices.size(); i++)
        {
            int element = prices[i];

            for (int j = i + 1; j < prices.size(); j++)
            {
                int max = prices[j] - element;

                res = std::max(res, max);
            }
        }

        if (res > 0)
        {
            return res;
        }

        return 0;
    }

private:
    int res = 0;
};