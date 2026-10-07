class Solution {
public:
    vector<bool> cols, diag, anti_diag; 
    int totalNQueens(int n) {
    //total count of solutions...

    //we know  when we place a queen, the row and ciolumn and diagonal is blocked if
    //placed (1,0), then everything x=1 and y = 0 and any diagonal is blocked.

    cols.assign(n, false);         
    diag.assign(2*n-1, false );
    anti_diag.assign(2*n-1, false);
    //diag starts from top left to bottom right
    //0,2 to 1,3 x-y   all x-y same

    //oppsoite is x+y like 0,3  1,2 etc
    //anti diag botttom left to top right
    int counter = 0;
    //back tracking using stack?

    backtrack(0,n,counter);
    return counter;
    }

    void backtrack(int r, int n, int& count){
        if (r >= n){// places all n queens
            count++;
            return;
        }    
 
        for (int j = 0; j < n; j++){

            if (cols[j] || diag[r-j + n- 1] || anti_diag[r+j ]){
                continue;
            }
            //we can place
            cols[j] = true;
            diag[r-j + n -1 ] = true;
            anti_diag[r+j] = true;

            backtrack(r+1,n,count);

            //backtrack
            cols[j] = false;
            diag[r-j + n -1 ] = false;
            anti_diag[r+j] = false;

        }
    }
};