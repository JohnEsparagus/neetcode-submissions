class Solution {
public:

    vector<bool> cols, diag, anti_diag;
    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n) {
        cols.assign(n, false) ;// each col
        diag.assign(2* n - 1, false); // each diag top lfet to bottom right i-j
        anti_diag.assign(2 *n - 1, false); //each diag bottom left to top right i + j

        vector<pair<int,int>> path;
        recursion(0,n,path);
        return result;
        
    }

    void recursion(int r, int n, vector<pair<int,int>>& path){
        if (r == n) //when r is max, we have alr placed on n squares.
        {
            std::vector<std::string> board(n, std::string(n, '.'));
            
            for (const auto& coordinate : path) {
                int row = coordinate.first;
                int col = coordinate.second;
                
                if (row >= 0 && row < n && col >= 0 && col < n) {
                    board[row][col] = 'Q';
                }
            }

            result.push_back(board);
            
        }
        for (int c = 0; c < n; c++){
            if (cols[c] || diag[r-c + n - 1] || anti_diag[r+c]){
                continue;
            }
            //milgaya
            cols[c]= true;
            diag[r-c + n - 1]= true;
            anti_diag[r+c] = true;
            path.push_back({r,c});

            recursion(r+1, n, path);

            cols[c]= false;
            diag[r-c + n - 1]= false;
            anti_diag[r+c] = false;
            path.pop_back();

        }

    }
};
