class Solution {
public:
    long long sumAndMultiply(int n) 
    {
        std::string x = to_string(n);
        std::string res = "";

        //Get x
        for (char c : x)
        {
            if (c != '0')
            {
                res += c;
            }
        }   

        //Gets sum
        int res2 = 0;

        for (char c : res)
        {
            int num = c - '0';
            res2 += num;
        }

        return multiplySum(res, res2);
    }

    long long multiplySum(std::string res, int res2)
    {
        if (res.empty())
        {
            return 0;
        }

        long long num = stoll(res);
        return num * res2;
    }

};