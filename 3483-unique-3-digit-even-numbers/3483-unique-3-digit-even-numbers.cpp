class Solution {
public:
    int totalNumbers(vector<int>& digits) 
    {
        unordered_set<int> hashy;

        for (int i{}; i < digits.size(); i++)
        {

            //No leading zero
            if (digits[i] == 0)
            {
                continue;
            }

            for (int j{}; j < digits.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }

                for (int k{}; k < digits.size(); k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }

                    //Last element has to be zero
                    if (digits[k] % 2 != 0)
                    {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    hashy.insert(num);
                }
            }
        }

        return (int)hashy.size();
    }

private:
    int res = 0;
};