class Solution {
public:
    int maxProduct(int n) 
    {
        std::string s = std::to_string(n);

        //Sort
        std::sort(s.begin(), s.end());

        int last = s.size() - 1;
        int sLast = s.size() - 2;

        return (s[last] - '0') * (s[sLast] - '0');
    }
};