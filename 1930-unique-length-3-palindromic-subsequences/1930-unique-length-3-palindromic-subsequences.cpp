class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        
        //Store each thing in HashMap
        for (int i = 0; i < s.size(); i++)
        {;
            dict[s[i]].push_back(i);
        }

        printHashMap(dict);



        for (const auto& [key, value] : dict)
        {
            int n = value.size();

            if (n >= 2)
            {
                int firstVal = value[0];
                int secondVal = value[n-1];

                //Find middles value
                bool seen[26] = {false};

                //Use seen array and convert value to a char.
                //Mapping the char to an index value to we can safely store it in seen array (tracks unique)
                //Can use a set
                for (int i = firstVal + 1; i < secondVal; i++)
                {
                    seen[s[i] - 'a'] = true;
                }

                for (int i = 0; i < 26; i++)
                {
                    if (seen[i])
                    {
                        res += 1;
                    }
                }

            }

        }

        return res;
    }

    void printHashMap(const unordered_map<char, vector<int>>& dict)
    {
        for (const auto& [key, vec] : dict)
        {
            std::cout << key << " : [";

            for (int i = 0; i < vec.size(); i++)
            {
                std::cout << vec[i];
                if (i + 1 < vec.size()) std::cout << ", ";
            }

            std::cout << "]" << std::endl;
        }
    }

private:
    unordered_map<char, vector<int>> dict;
    int res = 0;
};