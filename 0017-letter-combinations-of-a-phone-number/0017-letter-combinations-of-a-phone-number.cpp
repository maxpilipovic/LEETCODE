class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {

        if (digits.empty())
        {
            cout << "here" << endl;
            return res;
        }

        backtrack("", digits, 0);
        return res;
    }

    void backtrack(string curr, string& digits, int i)
    {

        //Base Case
        if (i == digits.size())
        {
            res.push_back(curr);
            return;
        }

        string letters = map[digits[i]];
        //Recursive
        for (char c : letters)
        {
            curr.push_back(c);
            backtrack(curr, digits, i + 1);
            curr.pop_back();
        }
    }

private:
    vector<string> res;
    unordered_map<char, string> map = 
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

};