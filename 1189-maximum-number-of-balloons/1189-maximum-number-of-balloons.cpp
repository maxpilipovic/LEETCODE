class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char, int> map;

        for (int i{}; i < text.size(); i++)
        {
            map[text[i]] += 1;
        }    

        std::string x = "balon";

        for (char c : x)
        {
            if (c == 'l' || c == 'o')
            {
                res = min(res, (map[c] / 2));
            }
            else
            {
                res = min(res, map[c]);
            }
        }

        return res;
    }

private:
    int res = INT_MAX;
};