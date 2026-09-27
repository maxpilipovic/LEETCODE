class Solution {
public:
    string reverseParentheses(string s) 
    {
        std::stack<char> st;

        for (char c : s)
        {
            if (c == ')')
            {
                //Temp string
                std::string t = "";

                while (st.top() != '(')
                {
                    char x = st.top();
                    st.pop();
                    t.push_back(x);
                }

                //Pop the '('
                st.pop();

                //Add t
                for (char l : t)
                {
                    st.push(l);
                }

            }
            else
            {
                st.push(c);
            }
        }

        std::string x = "";

        //Pop everything
        while (!st.empty())
        {
            //Grab top value
            char c = st.top();

            //Add to string
            x += c;

            //Pop
            st.pop();
        }

        //Reverse again
        std::reverse(x.begin(), x.end());

        return x;
    }

private:

};