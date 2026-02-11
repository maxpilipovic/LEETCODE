class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        //Exact matches.
        unordered_set<string> exact;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        //Create Mappings
        for (size_t i{}; i < wordlist.size(); i++)
        {
            string word = wordlist[i];

            //Add to exact.
            exact.insert(word);

            string lw = toLower(word);
            if (caseMap.find(lw) == caseMap.end())
            {
                caseMap[lw] = word;
            }

            string vowel = devowel(lw);
            if (vowelMap.find(vowel) == vowelMap.end())
            {
                vowelMap[vowel] = word;
            }

        }

        //Implementation
        for (size_t i{}; i < queries.size(); i++)
        {
            std::string word = queries[i];

            //Check exact match
            if (exact.count(word))
            {
                res.push_back(word);
                continue;
            }

            //Check toLower
            std::string lowerWord = toLower(word);
            if (caseMap.find(lowerWord) != caseMap.end())
            {
                res.push_back(caseMap[lowerWord]);
                continue;
            }

            //Check vowel
            std::string vowel = devowel(lowerWord);
            if (vowelMap.find(vowel) != caseMap.end())
            {
                res.push_back(vowelMap[vowel]);
                continue;
            }

            //Then, null string
            res.push_back("");


        }

        return res;
    }

    std::string createNew(std::string query)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (size_t i{}; i < query.size(); i++)
        {
            if (vowels.count(query[i]))
            {
                query[i] = '*';
            }
        }

        return query;
    }



private:
    static bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    static string toLower(const string& s)
    {
        string t = s;
        for (char& ch : t) 
        {
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        }
        return t;
    }

    static string devowel(const string& s) 
    {
        string t = s;
        for (char& ch : t) 
        {
            if (isVowel(ch)) 
            {
                ch = '*';
            }
        }
        return t;
    }

    vector<std::string> res;
};