class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> stack;

        int best = 0;

        for (int i{}; i <= heights.size(); i++)
        {
            int curr = (i == n) ? 0 : heights[i];

            while (!stack.empty() && curr < heights[stack.top()])
            {
                int h = heights[stack.top()];
                stack.pop();

                int width = stack.empty() ? i : i - stack.top() - 1;

                best = max(best, h * width);
            }

            stack.push(i);
        }

        return best;
    }

private:

};