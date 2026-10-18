class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n = prices.size();
        std::stack<int> mx;
        vector<int> res(n);

        for (int i{}; i < prices.size(); i++)
        {
            
            while(!mx.empty() && prices[i] <= prices[mx.top()])
            {
                int index = mx.top();
                mx.pop();
                res[index] = prices[index] - prices[i];
            }

            mx.push(i);
        }

        while (!mx.empty())
        {
            int index = mx.top();
            mx.pop();
            res[index] = prices[index];

        }

        return res;
    }

private:

};