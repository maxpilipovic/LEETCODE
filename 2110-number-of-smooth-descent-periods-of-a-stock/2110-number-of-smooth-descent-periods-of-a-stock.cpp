class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        for (int i = 0; i < prices.size(); i++)
        {
            if (stack.empty())
            {
                stack.push(prices[i]);
            }
            else if (!stack.empty() && stack.top() == prices[i] + 1)
            {
                //Smooth descent! Append
                stack.push(prices[i]);
            }
            else
            {
                long long count = stack.size();
                res += count * (count + 1) / 2;

                while (!stack.empty())
                {
                    stack.pop();
                }

                stack.push(prices[i]);
            }
        }

        //Forgot to flush stack??? What's left over
        long long count = stack.size();
        res += count * (count + 1) / 2;

        return res;
    }

private:
    std::stack<int> stack;
    long long res = 0;
};