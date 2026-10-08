class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        std::stack<char> stack;

        int balance = 0;

        for (int i{}; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                //So it skips outermost pair!
                if (balance > 0)
                {
                    stack.push('(');
                }

                balance += 1;
            }
            else
            {

                balance -= 1;

                if (balance > 0)
                {
                    stack.push(')');
                }
            }
        }

        std::string res = "";

        //Pop from stack
        while (!stack.empty())
        {
            char c = stack.top();
            stack.pop();
            
            //Add to res
            res += c;
        }

        //Reverse
        std::reverse(res.begin(), res.end());

        return res;
    }

private:

};