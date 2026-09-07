class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {

        std::string res = "";
        std::stack<int> x;

        for (char c : s)
        {
            if (std::isalnum(c))
            {
                res.push_back(c);
            }
            else if (c == '(')
            {
                x.push(res.size());
                res.push_back(c);
            }
            else if (c == ')')
            {
                if (!x.empty())
                {
                    x.pop();
                    res.push_back(c);
                }
                else
                {

                }
            }
        }   

        //Remove extra shit
        while (!x.empty()) 
        {
            res.erase(res.begin() + x.top());
            x.pop();
        }

        return res; 
    }
};