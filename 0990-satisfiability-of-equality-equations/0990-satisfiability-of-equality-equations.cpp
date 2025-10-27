class Solution {
public:

    //Constructor
    Solution()
    {

        parent.resize(26);
        size.resize(26, 1);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }

    }

    bool equationsPossible(vector<string>& equations) {
        
        //2 Different Parts...
        //1. ==
        //2. != 

        //==

        for (auto& equation : equations)
        {
            if (equation[1] == '=')
            {
                int firstPart = equation[0] - 'a';
                int secondPart = equation[3] - 'a';

                uunion(firstPart, secondPart);
            }
        }

        //!=
        for (auto& equation : equations)
        {
            if (equation[1] == '!')
            {
                int firstPart = equation[0] - 'a';
                int secondPart = equation[3] - 'a';

                if (find(firstPart) == find(secondPart))
                {
                    return false;
                }
            }
        }

        return true;
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x]; //We found it...
    }

    void uunion(int x, int y) //union
    {

        //Find the root of x & y
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {

            //Add them together???
            if (size[rootX] < size[rootY])
            {
                parent[rootY] = rootX;
                size[rootX] += rootY; //Add the entire thing
            }
            else
            {
                parent[rootX] = rootY;
                size[rootY] += rootX;
            }
        }
    }


private:
    vector<int> parent;
    vector<int> size;
};