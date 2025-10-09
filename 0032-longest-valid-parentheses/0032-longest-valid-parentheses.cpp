#include <stack>

class Solution {
public:
    int longestValidParentheses(string s) {

        int openBracket = 0;
        int closeBracket = 0;
        int n = s.size();
        stack.push(-1);
        
        //Put's open brackets in stack.
        //putInStack(s);

        for (int i = 0; i < n; i++)
        {
            
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else 
            {

                stack.pop();

                // ")" ? Why we push this on our stack?
            
                //Grab the top.
                //Stack is empty...

                if (stack.empty())
                {
                    //Find the max
                    stack.push(i);
                }
                else
                {
                    max = std::max(max, i - stack.top());
                }
            }
        } 

        return max;
    }

private:
    int max = 0;
    stack<int> stack; 
};