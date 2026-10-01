class Solution {
public:
    bool isValid(string s) 
    {
        
        int sBracket = 0;
        int cBracket = 0;
        int nBracket = 0;

        std::stack<char> stack;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else if (c == ')' && !stack.empty())
            {
                char d = stack.top();
                stack.pop();

                if (d != '(')
                {
                    return false;
                }
            }
            else if (c == ']' && !stack.empty())
            {
                char d = stack.top();
                stack.pop();

                if (d != '[')
                {
                    return false;
                }
            }
            else if (c == '}' && !stack.empty())
            {
                char d = stack.top();
                stack.pop();

                if (d != '{')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }    

        return stack.empty();
    }

private:

};