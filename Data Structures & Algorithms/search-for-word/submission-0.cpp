class Solution {
public:
    int row;
    int col;

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        // all words have been found. 
        if (i>=row || i<0 || j>=col || j<0) return false;
        if (board[i][j] != word[k]) return false;
        if (k==word.size()-1) return true; 

        char temp = board[i][j];
        board[i][j] = '#'; // visited
        bool found = (dfs(board,word,i+1,j,k+1) || dfs(board,word,i,j+1,k+1) ||
                      dfs(board, word,i-1,j,k+1) || dfs(board,word,i,j-1,k+1));
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j]==word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
