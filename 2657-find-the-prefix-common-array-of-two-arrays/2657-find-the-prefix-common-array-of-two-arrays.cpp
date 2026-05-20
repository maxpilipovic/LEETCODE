class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        vector<int> x(A.size(), 0);
        unordered_set<int> visited;

        int count = 0;

        for (int i{}; i < B.size(); i++)
        {
            res[B[i]] += 1;
            res[A[i]] += 1;

            if (res[B[i]] >= 2 && visited.find(B[i]) == visited.end())
            {
                count += 1;
                visited.insert(B[i]);
            }

            if (res[A[i]] >= 2 && visited.find(A[i]) == visited.end())
            {
                count += 1;
                visited.insert(A[i]);
            }

            //Add it to vec
            x[i] = count;
        }


        return x;
    }

private:
    unordered_map<int, int> res;
};