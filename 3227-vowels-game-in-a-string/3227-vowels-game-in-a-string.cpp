class Solution {
public:
    bool doesAliceWin(string s) {

        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.count(s[i]))
            {
                return true;   
            }
        }   

        return false;
    }

private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
};