class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size() - 1;
        backtrack(res, curr, s, 0, currVec, n);

        return res;
    }

    void backtrack(vector<vector<std::string>>& res, std::string& curr, std::string& s, int start, vector<std::string>& currVec, int n)
    {
        //Base Cases
        //len 1 curr's - ALWAYS PALINDROME
        //if (curr.size() == 1)
        //{
           // currVec.push_back(curr);
            //res.push_back(currVec);
            //return;
        //}

        if (start == s.length())
        {
            res.push_back(currVec);
            return;
        }

        //Recursive...
        for (int i = start; i < s.size(); i++)
        {
            std::string substring = s.substr(start, i - start + 1);
            if (checkPalindrome(substring, 0, substring.length() - 1))
            {
                currVec.push_back(substring);
                backtrack(res, curr, s, i + 1, currVec, n);
                currVec.pop_back();
            }
        }
    }

    bool checkPalindrome(std::string substring, int i, int j)
    {
        //PALINDROME CHECK - Two pointer.
        while (i < j)
        {

            if (substring[i] != substring[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

private:
    vector<vector<std::string>> res;
    vector<std::string> currVec;
    std::string curr;
};