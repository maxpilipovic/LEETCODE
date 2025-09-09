#include <set>
#include <tuple>
#include <queue>

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        //Here we loop over the array...
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {

                if (grid[row][col] == 1 && hashy.find({row, col}) == hashy.end())
                {
                   std::cout << "xd" << std::endl; 
                   bfs(grid, row, col, cols, rows);
                   //count++;
                }
            }
        }

        return maxArea;
            
    }

    void bfs(vector<vector<int>>& grid, int row, int col, int cols, int rows)
    {
        int area = 0;
        queue.push({row, col});
        hashy.insert({row, col});

        while (!queue.empty())
        {
            //1. I want to add to hashy
            //2. Make adjuystments in bfs.. Which we will see further and add to queue.

            std::tuple<int, int> element = queue.front();
            queue.pop();

            //Split up element into row & col
            int nRow = std::get<0>(element);
            int nCol = std::get<1>(element);
            area++;
            //int nArea = std::get<2>(element);

            //Update our max
            cout << maxArea << std::endl;
            maxArea = std::max(maxArea, area);

            for (auto [dRow, dCol] : directions)
            {
                //Getting our newRow, newCol
                int newRow = nRow + dRow;
                int newCol = nCol + dCol;

                //Check our bounds && check if grid[row][col] == 1 && not in hashy.

                if ( 0 <= newRow && newRow < rows &&
                     0 <= newCol && newCol < cols &&
                     grid[newRow][newCol] == 1 &&
                     hashy.find({newRow, newCol}) == hashy.end())
                {
                    //1. Wanna add its neighbor to q
                    //2. Want to add to hashy to keep track of seen vals.
                    hashy.insert({newRow, newCol});
                    queue.push({newRow, newCol});

                }
            }
        }
    }

private:

    int maxArea = 0;
    int count = 0;
    std::set<std::tuple<int, int>> hashy; 
    std::queue<std::tuple<int, int>> queue;
    vector<tuple<int, int>> directions = {
        {0, -1},  // north
        {0, 1},   // south
        {1, 0},   // east
        {-1, 0}   // west
    };

};