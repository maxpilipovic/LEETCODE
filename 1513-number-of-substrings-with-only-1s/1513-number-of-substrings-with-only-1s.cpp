class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7; 
        long long countOnes = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                countOnes += 1;
            }
            if (s[i] == '0' || i == s.size() - 1)
            {
                //cout << "inside loop" << endl;
                if (countOnes > 0)
                {
                    //cout << "factorial" << endl;
                    res = (res + factorial(countOnes)) % MOD;
                }

                countOnes = 0;
            }
        }

        return (int)res;

    }

    long long factorial(long long countOnes)
    {
        //cout << "here" << std::endl;
        if (countOnes == 1)
        {
            return 1;
        }

        return countOnes + factorial(countOnes - 1);
    }

private:
    long long res = 0;
};