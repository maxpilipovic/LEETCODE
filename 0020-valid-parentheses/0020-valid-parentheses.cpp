class Solution {
public:
    bool isValid(std::string s) {
        
        std::stack<char> stack;

        for (int i = 0; i < s.size(); i++)
        {
            if (!stack.empty() && (s[i] == '}' || s[i] == ')' || s[i] == ']'))
            {
                char c = stack.top();
                
                switch (s[i])  // switch on the current closing bracket
                {
                    case ')':
                        if (c != '(') return false;
                        break;
                    case '}':
                        if (c != '{') return false;
                        break;
                    case ']':
                        if (c != '[') return false;
                        break;
                }

                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }
        }

        return (stack.size() == 0);
    }
};