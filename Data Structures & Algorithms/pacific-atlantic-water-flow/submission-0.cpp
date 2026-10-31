class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //from ocean imagine rising sea levels
        //for each cell we run algorithm

        //we flood all cells from apceific side using dfs// bfs
        //if we cross, we mark.

        //flood sides from atlandtic side using ffs or bfs if we cross we mark
        // we go from cell lower to a higher cell.
        //this ensures that water dropped on that cell would reach the pacific and atlantic.
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<int>> marked(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> out;

        int check = 1 ;//pacific

        for (int i = 0; i < COLS; i++){
            dfs(heights, 0, i, marked, check);
        }
        for (int j = 0; j < ROWS; j++){
            dfs(heights, j, 0,marked, check);

        } //        
        check = 2 ;//atlantic


        for (int i = 0; i < COLS; i++){
            dfs(heights, ROWS - 1, i, marked,check);
        }

        for (int j = 0; j < ROWS; j++){
            dfs(heights,  j, COLS - 1, marked,check);
        } //atlantic

        for (int i =0 ; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                if (marked[i][j] == 3){
                    out.push_back({i,j});
                }
            }

        }
        return out;
        



    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& marked, int check ){
        int ROWS = heights.size();
        int COLS = heights[0].size();
        //only explore others if curr height is < neihhbour
        if (min(r,c) < 0 || r > ROWS - 1 || c > COLS - 1 || (marked[r][c] & check) ){
            return;
        } 
        if (marked[r][c] & check) return; 

        marked[r][c] |= check;

        int h = heights[r][c];
        if (r+1 < ROWS && heights[r+1][c] >= h) dfs(heights, r+1, c, marked, check);
        if (r-1 >= 0    && heights[r-1][c] >= h) dfs(heights, r-1, c, marked, check);
        if (c+1 < COLS && heights[r][c+1] >= h) dfs(heights, r, c+1, marked, check);
        if (c-1 >= 0    && heights[r][c-1] >= h) dfs(heights, r, c-1, marked, check);
    }

};
