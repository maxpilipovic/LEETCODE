class Solution {
public:
    string sortVowels(string s) {
        
        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                //We have found it
                vowelsFound.push_back(s[i]);
            }
        }

        printVec(vowelsFound);
        std::sort(vowelsFound.begin(), vowelsFound.end());
        printVec(vowelsFound);

        //Pointer to array
        int index = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                //We have found it
                s[i] = vowelsFound[index];
                index++;
            }
        }

        return s;
    }

    void printVec(vector<int>& vowelsFound)
    {
        cout << "[";
        for (int i = 0; i < vowelsFound.size(); i++)
        {
            cout << vowelsFound[i];

            if (i != vowelsFound.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }


private:

    string res = "Hello";
    vector<int> vowelsFound;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};





};