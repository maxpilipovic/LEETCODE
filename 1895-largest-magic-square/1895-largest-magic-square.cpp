class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid)
    {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        //rowPrefix[r][c+1] = sum of grid[r][0..c]
        vector<vector<int>> rowPrefix(rows, vector<int>(cols + 1, 0));
        //colPrefix[r+1][c] = sum of grid[0..r][c]
        vector<vector<int>> colPrefix(rows + 1, vector<int>(cols, 0));

        //diag1[r+1][c+1] = sum along (\) from (0,0) to (r,c)
        vector<vector<int>> diag1(rows + 1, vector<int>(cols + 1, 0));
        //diag2[r+1][c] = sum along (/) from (0,cols-1) direction; built right-to-left
        vector<vector<int>> diag2(rows + 1, vector<int>(cols + 1, 0));

        //Build rowPrefix + diag1
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                rowPrefix[r][c + 1] = rowPrefix[r][c] + grid[r][c];
                diag1[r + 1][c + 1] = diag1[r][c] + grid[r][c];
            }
        }

        //Build colPrefix
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                colPrefix[r + 1][c] = colPrefix[r][c] + grid[r][c];
            }
        }

        //Build diag2
        for (int r = 0; r < rows; r++) {
            for (int c = cols - 1; c >= 0; c--) {
                diag2[r + 1][c] = diag2[r][c + 1] + grid[r][c];
            }
        }

        auto rowSum = [&](int r, int c1, int c2) -> int {
            return rowPrefix[r][c2 + 1] - rowPrefix[r][c1];
        };
        auto colSum = [&](int c, int r1, int r2) -> int {
            return colPrefix[r2 + 1][c] - colPrefix[r1][c];
        };
        auto d1Sum = [&](int r1, int c1, int k) -> int { 
            int r2 = r1 + k, c2 = c1 + k;
            return diag1[r2][c2] - diag1[r1][c1];
        };
        auto d2Sum = [&](int r1, int c1, int k) -> int {
            int r2 = r1 + k, c2 = c1 + k;
            return diag2[r2][c1] - diag2[r1][c2];
        };

        //Try biggest k
        for (int k = min(rows, cols); k >= 1; k--) {
            for (int r1 = 0; r1 + k - 1 < rows; r1++) {
                for (int c1 = 0; c1 + k - 1 < cols; c1++) {

                    int target = rowSum(r1, c1, c1 + k - 1);

                    //Diagonals must match
                    if (d1Sum(r1, c1, k) != target) continue;
                    if (d2Sum(r1, c1, k) != target) continue;

                    bool ok = true;

                    //All rows match
                    for (int r = r1; r < r1 + k && ok; r++) {
                        if (rowSum(r, c1, c1 + k - 1) != target) ok = false;
                    }

                    //All cols match
                    for (int c = c1; c < c1 + k && ok; c++) {
                        if (colSum(c, r1, r1 + k - 1) != target) ok = false;
                    }

                    if (ok) return k;
                }
            }
        }

        return 1;
    }
};