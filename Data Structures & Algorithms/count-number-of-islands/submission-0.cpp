class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0, -1, 0, 1};
        queue<pair<int,int>> q;
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]=='1') {
                    ans++;
                    q.push({i,j});
                    grid[i][j]='0';

                    while (!q.empty()) {
                        auto it = q.front();
                        q.pop();
                        int r = it.first;
                        int c = it.second;

                        for (int k=0; k<4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1') {
                                grid[nr][nc]='0';
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
