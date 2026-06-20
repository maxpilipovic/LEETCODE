class Solution {
public:
    string removeStars(string s) 
    {
        int n = s.size();
        std::stack<char> stack;

        for (int i{}; i < n; i++)
        {
            //Grab char
            char c = s[i];

            if (c == '*')
            {
                char x = stack.top();
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }        

        while (!stack.empty())
        {
            res += stack.top();
            stack.pop();
        }   

        reverse(res.begin(), res.end());

        return res;
    }

private:
    std::string res = "";
};