class Solution {
public:
    int maxFreqSum(string s) {
        
        int max1 = maxVowels(s);
        int max2 = maxConsonants(s);

        return max1 + max2;
    }

    int maxVowels(string s)
    {
        //Builds our map
        for (char letter : s)
        {
            if (vowels.count(letter))
            {
               vowelsMap[letter] += 1; 
            }
        }

        int MAXVAL = 0;

        for (const auto& [key, value] : vowelsMap)
        {
            if (value > MAXVAL)
            {
                MAXVAL = value;
            }
        }

        return MAXVAL;
    }

    int maxConsonants(string s)
    {
        //Builds our map
        for (char letter : s)
        {
            if (!vowels.count(letter))
            {
               consonantsMap[letter] += 1; 
            }
        }

        int MAXVAL = 0;

        for (const auto& [key, value] : consonantsMap)
        {
            if (value > MAXVAL)
            {
                MAXVAL = value;
            }
        }

        return MAXVAL;


    }

private:

    unordered_map<char, int> vowelsMap;
    unordered_map<char, int> consonantsMap;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
};