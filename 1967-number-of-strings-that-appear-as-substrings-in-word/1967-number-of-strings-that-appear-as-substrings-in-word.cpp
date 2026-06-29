class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) 
    {
        for (int i{}; i < patterns.size(); i++)
        {
            if (word.contains(patterns[i]))
            {
                count += 1;
            }
        }    

        return count;
    }

private:
    int count = 0;
};