class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = INT_MAX;
        int profit = 0;

        for (int i{}; i < prices.size(); i++)
        {
            //Find min
            res = std::min(res, prices[i]);

            //Calc price
            profit = std::max(profit, prices[i] - res);

        }

        return profit > 0 ? profit : 0;
    }
};