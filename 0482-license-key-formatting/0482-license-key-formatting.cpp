class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {

        std::string res = "";

        for (int i{}; i < s.size(); i++)
        {
            char c = s[i];

            if (std::isalnum(c))
            {
                res.push_back(std::toupper(c));
            }
        } 

        int n = res.size();

        if (n == 0)
        {
            return "";
        }

        int first = n % k;

        if (first == 0) 
        {
            first = k;
        }

        //Returned string...
        std::string out = res.substr(0, first);

        for (int i = first; i < n; i += k)
        {
            out.push_back('-');
            out += res.substr(i, k);
        }

        return out;
    }

private:

};