class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int n = word.size(); 
        unordered_set<char> lower;
        unordered_map<char, int> map;

        for (int i{}; i < n; i++)
        {
            char c = word[i];

            if (std::islower(c))
            {
                lower.insert(c);

                //Get last occurence of the char
                map[c] = i;
            }
        }

        unordered_set<char> visited;

        //Second pass. LOOP over
        for (int i{}; i < n; i++)
        {
            char c = word[i];

            if (std::isupper(c) && !visited.contains(c))
            {
                char cx = std::tolower(c);
                visited.insert(c);

                if (lower.contains(cx) && map[cx] < i)
                {
                    res += 1;
                }
            }
        }

        return res;
    }

private:
    int res = 0;
};