class Solution {
public:
    string processStr(string s) 
    {
        std::string res = "";
        int n = s.size();

        for (int i{}; i < n; i++)
        {
            if (std::islower(s[i]))
            {
                res.push_back(s[i]);
            }
            else if (s[i] == '#')
            {
                std::string x = res;
                res += x;
            }
            else if (s[i] == '%')
            {   
                std::reverse(res.begin(), res.end());
            }
            else if (s[i] == '*')
            {
                if (!res.empty())
                {
                    res.pop_back();
                }
            }
        }   

        return res; 
    }
};