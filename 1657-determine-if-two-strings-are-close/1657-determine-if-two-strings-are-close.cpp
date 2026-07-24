class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        std::unordered_set<int> x;
        std::unordered_set<int> y;

        for (int i{}; i < word1.size(); i++)
        {
            x.insert(word1[i]);
        }

        for (int j{}; j < word2.size(); j++)
        {
            y.insert(word2[j]);
        }

        std::array<int, 26> count1{};
        std::array<int, 26> count2{};

        for (char c : word1) count1[c - 'a']++;
        for (char c : word2) count2[c - 'a']++;

        std::sort(count1.begin(), count1.end());
        std::sort(count2.begin(), count2.end());

        return (x == y && word1.size() == word2.size() && count1 == count2);
    }
};