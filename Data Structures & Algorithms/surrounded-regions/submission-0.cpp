class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size() - 1;
        int COLS = board[0].size() - 1;
        int r = 0;
        int c = 0;
        //square

        //if any region, 'connected vertically or horizontally O's, touches the edge, then it stays otherwise it goes.
        //edge = ROW = 0  / 

        //for each...

        for (int i = 0; i <= ROWS; i++){
            for (int j =0; j <= COLS; j++){
                if (i != 0 && i != ROWS && j != 0 && j != COLS) {
                    continue;
                }
                else if (board[i][j] == 'O'){
                    checkComponent(i,j,board); //fill it with T
                }
            }
        }


        for (int i = 0; i <= ROWS; i++){
            for (int j =0; j <= COLS; j++){
                //fill any remaining O with X
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
        
        
    }

    //do dfs on every island...
void checkComponent(int r, int c, vector<vector<char>>& grid) { 
    int max_m = grid.size() - 1; 
    int max_n = grid[0].size() - 1;

    // 1. Base Case: Out of bounds or water/empty cell ('0' as a char)
    if (r < 0 || r > max_m || c < 0 || c > max_n || grid[r][c] != 'O') { 
        return;
    } 

    grid[r][c] = 'T';

    // 4. Recurse in all 4 directions 
    checkComponent(r - 1, c, grid); 
    checkComponent(r + 1, c, grid); 
    checkComponent(r, c - 1, grid); 
    checkComponent(r, c + 1, grid); 

    // If this cell OR any connected neighbor touches the edge, return true 
}


};
