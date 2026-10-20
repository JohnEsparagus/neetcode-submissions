class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        vector<int> dp(matrix.size()+1);
        //choose smallest in dp amtrix?
        //best choice?
        
        //1st value?
        if (matrix.size() == 1){
            return matrix[0][0];
        }


        for (int r = 1 ; r < matrix.size(); r++){
            for (int c = 0; c  < matrix.size(); c++){
                int best_above = matrix[r - 1][c];

                if (c > 0){
                    best_above = min(best_above, matrix[r-1][c-1] );
                }

                if ( c + 1 < matrix.size()){
                    best_above = min(best_above, matrix[r-1][c+1]);
                }

                matrix[r][c] += best_above;
                //matrix += best...curr pos accumulation...

            }
        }

        int ans = matrix[matrix.size() - 1][0];
        for (int ind : matrix[matrix.size()-1]){
            ans = min(ans, ind);
        }
        return ans;

        
    }
};