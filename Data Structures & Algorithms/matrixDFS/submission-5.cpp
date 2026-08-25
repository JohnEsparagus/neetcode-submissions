class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {

        //we do this iteratively so...

        //requirements
        int COLS = grid[0].size();
        int ROWS = grid.size(); 
vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        int ans = 0;
        stack<tuple<int,int,bool>> st; 

        st.push({0,0,false});


        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while (!st.empty()){
            auto [r,c,isLeaving] = st.top();
            st.pop();

            if (min(r,c) < 0  || r >= ROWS || c >= COLS || grid[r][c] == 1){
                continue;
            }

            if (isLeaving){
                visited[r][c] = false;
                continue;
            }

            if (visited[r][c]){
                continue;
            }
          if (r == ROWS - 1 && c == COLS - 1) {
                ans++;
                continue;
            }
            visited[r][c] = true;
            st.push({r, c, true});
           
            for (int i = 0; i < 4; i++) {
                int nextR = r + dRow[i];
                int nextC = c + dCol[i];

                st.push({nextR, nextC, false});
            }
        }


        return ans;
        //can st remember the states???
        //maube a stack of tuple


        //now  we iterate through using dfs....




    }
};
