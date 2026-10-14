class Solution {
public:
    string maxSumOfSquares(int num, int sum) 
    {
        if ((long long)sum > 9LL * num)
        {
            return "";
        }

        std::string result = "";
        result.reserve(num);

        for (int i{}; i < num; i++)
        {
            int digit = min(9, sum);
            result += char('0' + digit);
            sum -= digit;
        }

        return result;
    }
private:

};