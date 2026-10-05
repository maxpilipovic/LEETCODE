class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        std::stack<int> stack;
        stack.push(0); //Score of outermost

        for (int i{}; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(0);
            }
            else
            {
                int top = stack.top();
                stack.pop();

                int value = (top == 0) ? 1 : 2 * top;

                stack.top() += value;
            }
        }

        return stack.top();
    }

private:

};