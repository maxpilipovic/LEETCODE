class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] - '0' > target - '0')
            {
                res = letters[i];
                break;
            }
        }

        if (res == '\0')
        {
            return letters[0];
        }

        return res;
    }

private:
    char res = '\0';
};