class Solution {
public:
    string smallestPalindrome(string s) 
    {

        //Base Case
        if (s.size() == 1)
        {
            return s;
        }

        std::map<char, int> x;

        for (int i{}; i < s.size(); i++)
        {
            x[s[i]] += 1;
        }

        //Find odd count char
        std::string mid = "";
        for (auto& [c, v] : x)
        {
            //Odd
            if (v % 2 != 0)
            {
                //Find odd val char
                mid = std::string(1, c);
            }
        } 
        std::string temp3 = "";
        temp3 = findSmallestPalindrome(temp3, x, s.size() / 2);
        std::string temp2 = temp3;
        reverse(temp2.begin(), temp2.end());

        return temp3 + mid + temp2;
    }

    std::string findSmallestPalindrome(std::string& temp, std::map<char, int>& x, int n)
    {

        //Base Case (left is half)
        if ((int)temp.size() >= n)
        {
            return temp;
        }

        //char, val in map
        for (auto& [c, v] : x)
        {
            if (v >= 2)
            {
                temp += c;

                //2 becuase we are mirroring
                v -= 2;
                return findSmallestPalindrome(temp, x, n);
            }
        }

        return temp;
    }

private:

};