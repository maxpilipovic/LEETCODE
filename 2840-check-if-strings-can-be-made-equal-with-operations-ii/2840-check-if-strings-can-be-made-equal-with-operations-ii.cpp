class Solution {
public:
    bool checkStrings(string s1, string s2) 
    {
        vector<int> even1(26, 0);
        vector<int> even2(26, 0);
        vector<int> odd1(26, 0);
        vector<int> odd2(26, 0);

        for (int i = 0; i < s1.size(); i++)
        {
            if (i % 2 == 0)
            {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }
            else
            {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        printVec(even1, "even1");
        printVec(even1, "even2");
        printVec(even1, "odd1");
        printVec(even1, "odd2");

        return even1 == even2 && odd1 == odd2;
    }

    void printVec(vector<int>& vec, string name)
    {
        cout << name << ": ";
        for (int i = 0; i < 26; i++)
        {
            if (vec[i] > 0)
            {
                cout << char('a' + i) << "=" << vec[i] << " ";
            }
        }
        cout << endl;
    }

};