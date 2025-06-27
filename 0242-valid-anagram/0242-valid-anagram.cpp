class Solution {
public:
    bool isAnagram(string s, string t) {
        
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;
        
        //Build our map
        for (size_t i = 0; i < s.length(); i++) 
        {

            if (s_map.contains(s[i]))
            {
                s_map[s[i]] += 1;
            }
            else 
            {
                s_map[s[i]] = 1;
            }
        }

        //Building our map
        for (size_t j = 0; j < t.length(); j++)
        {
            if (t_map.contains(t[j]))
            {
                t_map[t[j]] += 1;
            }
            else 
            {
                t_map[t[j]] = 1;
            }
        }
        
        for (const auto& pair : s_map)
        {
            std::cout << pair.first << "; " << pair.second << "\n";
        }
        
        std::cout << " " << "\n";

        for (const auto& pair : s_map)
        {
            std::cout << pair.first << "; " << pair.second << "\n";
        }

        return s_map == t_map;
    }
};