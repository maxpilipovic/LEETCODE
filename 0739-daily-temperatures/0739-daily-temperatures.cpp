#include <stack>;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::stack<int> stack;
        std::vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
        {

            while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int prevIndex = stack.top();
                stack.pop();
                res[prevIndex] = i - prevIndex;
            }
            stack.push(i);

        }
        return res;
    }
};