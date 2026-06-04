class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        //Base Case
        int x = num1;

        while (x <= num2)
        {   
            std::string strNum = std::to_string(x);

            if (strNum.size() >= 3)
            {
                findWaviness(strNum);
            }

            //Increase
            x += 1;
        }
        
        return res;
    }

    void findWaviness(std::string& num)
    {

        for (int i = 1; i < num.size() - 1; i++)
        {
            //Peak
            if (num[i - 1] < num[i] && num[i] > num[i + 1])
            {
                res += 1;
            }

            //Valley
            if (num[i - 1] > num[i] && num[i + 1] > num[i])
            {
                res += 1;
            }
        }

    }

private:
    int res = 0;
};