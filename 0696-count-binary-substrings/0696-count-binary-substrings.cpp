class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int n = (int)s.size();
        
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                continue;
            }

            char leftChar = s[i];
            char rightChar = s[i + 1];

            int L = i;
            int R = i + 1;
            int leftCount = 0; 
            int rightCount = 0;

            while (L >= 0 && s[L] == leftChar && R < n && s[R] == rightChar)
            {
                leftCount++;
                rightCount++;
                L--;
                R++;
                res++;
            }
        }

        return res;
    }

private:
    int res = 0;
};