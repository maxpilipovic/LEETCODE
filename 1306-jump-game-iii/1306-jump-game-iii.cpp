class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        return dfs(arr, start, visited); 
    }

    bool dfs(vector<int>& arr, int i, unordered_set<int>& visited)
    {

        //Check bounds first
        if (i >= arr.size())
        {
            return false;
        }

        if (i < 0)
        {
            return true;
        }

        //Check visited.
        if (visited.count(i))
        {
            return false;
        }

        //Add our visited...
        visited.insert(i);

        //Base Case
        if (arr[i] == 0)
        {
            return true;
        }

        //Choices
        return dfs(arr, i + arr[i], visited) || dfs(arr, i - arr[i], visited);
    }

private:
    unordered_set<int> visited;
};