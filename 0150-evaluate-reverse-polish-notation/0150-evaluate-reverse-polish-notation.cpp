class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        std::stack<int> stack;

        for (int i{}; i < tokens.size(); i++)
        {

            std::string s = tokens[i];

            if (s == "*" || s == "+" || s == "/" || s == "-")
            {
                int b = stack.top();
                stack.pop();

                int a = stack.top();
                stack.pop();

                if (s == "+")
                {
                    stack.push(a + b);
                }
                else if (s == "-")
                {
                    stack.push(a - b);
                }
                else if (s == "*")
                {
                    stack.push(a * b);
                }
                else
                {
                    stack.push(a / b);
                }
            }
            else
            {
                int x = std::stoi(s);
                stack.push(x);
            }

        } 

        return stack.top();
    }

private:

};