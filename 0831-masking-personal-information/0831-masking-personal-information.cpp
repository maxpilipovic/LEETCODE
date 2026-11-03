class Solution {
public:
    string maskPII(string s) 
    {
        //Decide whether email or phone

        if (s.find('@') != string::npos)
        {
            return calcEmail(s);
        }
        else
        {
            return calcPhone(s);
        }
    }

    std::string calcEmail(const std::string& s)
    {
        string lower = "";

        for (char c : s)
        {
            lower += tolower(c);
        }

        size_t at = lower.find('@');

        //Frst letter + 5 stars + last letter of name, then @domain
        return lower.substr(0, 1) + "*****" + lower.substr(at - 1);
    }

    std::string calcPhone(const std::string& s)
    {
        string digits= "";

        for (char c : s)
        {
            if (isdigit(c))
            {
                digits += c;
            }
        }

        string local = "***-***-" + digits.substr(digits.size() - 4);
        int countryLen = digits.size() - 10;

        if (countryLen == 0)
            return local;

        return "+" + string(countryLen, '*') + "-" + local;
    }

private:

};