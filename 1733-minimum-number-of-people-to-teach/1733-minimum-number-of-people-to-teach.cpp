class Solution {
public:

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        //1. We need to build a set of langauges for each person.
        buildLanguages(languages);
        printMap(languageRelationships);

        //2. Identify which relationships need teaching.
        findCandidates(friendships);
        printSet(candidates);
        
        //3. We now ant to check how many languages
        buildMinimumLearn();
        printMap2(commonVals);

        //4. Find our min.
        res = findMinimumLearn();

        return res;
    }

    int findMinimumLearn()
    {

        if (commonVals.empty()) return 0;
        
        int max = 0;
        int maxPeople = candidates.size(); 

        for (const auto& pair : commonVals)
        {
            int value = pair.second;

            if (value > max)
            {
                max = value;
            }
        }

        return maxPeople - max;
    }

    void buildMinimumLearn()
    {
        //1. We need to find the most frequent teaching...
        //Hashmap???
        
        for (auto it = candidates.begin(); it != candidates.end(); ++it)
        {
            //*it dereference
            auto& list = languageRelationships[*it];

            for (auto it2 = list.begin(); it2 != list.end(); ++it2)
            {
                commonVals[*it2] += 1;
            }
        }
    }

    void printMap2(const unordered_map<int, int>& hashy)
    {
        if (hashy.empty()) 
        {
            std::cout << "Map is empty" << std::endl;
            return;
        }

        for (const auto& pair : hashy) 
        {
            std::cout << "Key " << pair.first 
                    << " -> Value " << pair.second << std::endl;
        }
    }

    void findCandidates(const vector<vector<int>>& friendships)
    {

        //2. Identify which relationships need teaching.
        for (const auto& friendship : friendships )
        {
            //Grab two values.
            int p1 = friendship[0];
            int p2 = friendship[1];

            bool flag = false;
            
            for (int lang : languageRelationships[p1])
            {
                if (languageRelationships[p2].count(lang))
                {
                    //We know we have a language so each person can speak
                    flag = true;
                    break;
                }
                //Get languages...

            }

            if (!flag)
            {
                candidates.insert(p1);
                candidates.insert(p2);
            }
        }
        
    }

    void buildLanguages(const vector<vector<int>>& languages)
    {
        for (int i = 0; i < languages.size(); i++)
        {
            for (int language : languages[i])
            {
                //Deal with 0. -> 1
                auto& valueSet = languageRelationships[i+1];
                valueSet.insert(language);
            }
        }

    }

    void printSet(unordered_set<int>& set)
    {
        for (auto it = set.begin(); it != set.end(); ++it)
        {
            std::cout << *it;

            if (next(it) != set.end()) 
            {
                std::cout << ", ";
            }
        }
    }
    void printMap(const unordered_map<int, unordered_set<int>>& hashy)
    {
        if (hashy.empty()) 
        {
            std::cout << "Map is empty" << std::endl;
            return;
        }
    
        std::cout << "Map contents:" << std::endl;
        for (const auto& pair : hashy) 
        {
            std::cout << "Person " << pair.first << ": [";
    
            const auto& langs = pair.second;
            int count = 0;

            for (auto it = langs.begin(); it != langs.end(); ++it) 
            {
                std::cout << *it;
                if (next(it) != langs.end()) 
                {
                    std::cout << ", ";
                }
                count++;
            }
            std::cout << "]" << std::endl;
        }
    }

private:
    int res = 0;
    unordered_map<int, unordered_set<int>> languageRelationships;
    unordered_map<int, int> commonVals;
    unordered_set<int> candidates;
    //int res = 0;
};