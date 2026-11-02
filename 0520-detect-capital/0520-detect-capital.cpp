class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool isAllCapital = true;
        bool isAllLowercase = true;
        bool isFirstLetter = std::isupper(word[0]);

        for (int i{}; i < word.size(); i++)
        {
            char c = word[i];

            //1. All uppercase.
            if (!std::isupper(c))
            {
                isAllCapital = false;
            }

            //2. All lowercase
            if (!std::islower(c))
            {
                isAllLowercase = false;
            }

            //3. First letter uppercase.
            if (i > 0 && !std::islower(c))
            {
                isFirstLetter = false;
            }
        }    

        return isAllCapital || isAllLowercase || isFirstLetter;
    }

private:

};