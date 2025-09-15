#include <cctype>
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        stringToSet(brokenLetters);

        //Make the vector
        std::istringstream iss(text);
        std::string word;

        while (iss >> word)
        {
            stringVec.push_back(word);
        }

        //printVec(stringVec);

        for (auto& word : stringVec)
        {
            if (maxWords(stringSet, word))
            {
                res += 1;
            }
        }

        return res;   
    }

    void stringToSet(string brokenLetters)
    {
        for (int i = 0; i < brokenLetters.size(); i++)
        {
            stringSet.insert(brokenLetters[i]);
        }
    }

    bool maxWords(unordered_set<char> stringSet, string word)
    {
        
        for (int i = 0; i < word.size(); i++)
        {

            if (stringSet.find(word[i]) != stringSet.end())
            {
                return false;
            }
        }

        return true;
    }

    void printVec(const std::vector<std::vector<std::string>>& vec) 
    {
        for (const auto& row : vec) 
        {
            for (size_t j = 0; j < row.size(); ++j) 
            {
                std::cout << row[j];
                if (j < row.size() - 1) 
                {
                    std::cout << "\t"; // Tab separator
                }
            }
            std::cout << std::endl;
        }
    }

private:
    int res = 0;
    unordered_set<char> stringSet;
    vector<std::string> stringVec;
};