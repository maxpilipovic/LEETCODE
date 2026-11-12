class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        int n = s.size();
        int m = goal.size();

        //Base Case
        if (n != m)
        {
            return false;
        }

        for (int i{}; i < s.size(); i++)
        {
            std::string local = "";
            local += s[i];

            //Initalize j
            int j = i + 1;

            if (j >= n)
            {
                j = 0;
            }

            while (j != i)
            {

                //Add to local
                local += s[j];

                //Increase
                j += 1;

                //Wrap
                if (j >= n)
                {
                    j = 0;
                }
            }

            if (local == goal)
            {
                return true;
            }
        }

        return false;
    }

private:

};