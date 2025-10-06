class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> T(n, vector<int>(n, INT_MAX)); 
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        queue<pair<int,int>> q;
        T[0][0] = grid[0][0];
        q.push({0,0});

        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();

            for(auto &[dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newT = max(T[r][c], grid[nr][nc]);
                    if(newT < T[nr][nc]) {
                        T[nr][nc] = newT;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return T[n-1][n-1];
    }
};