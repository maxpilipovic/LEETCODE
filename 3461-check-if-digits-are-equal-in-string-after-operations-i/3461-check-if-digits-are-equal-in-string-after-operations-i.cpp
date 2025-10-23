class Solution {
public:
    bool hasSameDigits(string s) {

        //Base Case
        if (s.size() < 2)
        {
            return false;
        }

        string newS = s;

        while (newS.size() > 2)
        {
            string curr;

            for (int i = 1; i < newS.size(); i++)
            {
                
                //Working with chars gotta convet
                int first = newS[i - 1] - '0';
                int second = newS[i] - '0';

                int ans = (first + second) % 10;
                curr.push_back(ans + '0');
            }

            newS = curr;
        }

        std::cout << newS << std::endl;

        return checkIfSame(newS);
    }

    bool checkIfSame(const std::string& word)
    {
        if (word[0] == word[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }


private:
    //bool res = false;
};