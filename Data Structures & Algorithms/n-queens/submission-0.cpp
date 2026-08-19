class Solution {
public:
    vector<vector<string>> ans;
    int t;
    void solve(int r, vector<string>& board, vector<bool>& col, vector<bool>& diag, vector<bool>& antidiag) {
        if (r==t) {
            ans.push_back(board);
            return;
        }
        for (int c=0; c<t; c++) {
            if (!diag[r+c] && !antidiag[r-c+t-1] && !col[c]) {
                board[r][c]='Q';
                col[c]=true;
                diag[r+c]=true;
                antidiag[r-c+t-1]=true;

                solve(r+1, board, col, diag, antidiag);

                board[r][c] = '.';
                col[c]=false;
                diag[r+c]=false;
                antidiag[r-c+t-1]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int r = 0;
        t=n;
        vector<string> board(n, string(n,'.'));
        vector<bool> col(n, false);
        vector<bool> diag(2*n-1);
        vector<bool> antidiag(2*n-1);
        solve(r, board, col, diag, antidiag);
        return ans;
    }
};
