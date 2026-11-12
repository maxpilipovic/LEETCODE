class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        std::string copy = "";
        int count = 0;

        while (copy.size() < b.size())
        {
            copy += a;
            count += 1;
        }

        //If its there. Return it.
        if (copy.find(b) != string::npos)
        {
            return count;
        }    

        //Add one more just in case its at the end
        copy += a;

        if (copy.find(b) != string::npos)
        {
            return count + 1;
        }

        return -1;
    }
};