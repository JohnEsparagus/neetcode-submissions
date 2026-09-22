class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        //matrix flipped over diagonal
        int COLS = matrix[0].size();
        int ROWS = matrix.size();

        if (COLS != ROWS){
            //make new matrix
            vector<vector<int>> transposed(COLS, vector<int>(ROWS));

            for (int i = 0; i < ROWS; i++){
                for (int j = 0; j < COLS; j++){
                    transposed[j][i] = matrix[i][j];
                }
            }
            return transposed;
        }

        
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < i; j++){//undo's itself so 
                if (i == j ){
                    continue;
                }
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        return matrix;
        
    }
};