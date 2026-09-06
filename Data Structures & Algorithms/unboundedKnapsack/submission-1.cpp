class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {

        int M = profit.size();
        int N = capacity;
        std::vector<std::vector<int>> dp(M+1,std::vector<int>(N + 1, 0));

        //fill dp with max profit at each price at each capacity.
        //fill again or dont fill.
        for (int i = 1; i <= M; i++){             
            for (int j = 0; j <= capacity; j++){

                if (j < weight[i-1]){
                    // fill with prev price at same j
                    dp[i][j] = dp[i-1][j];
                    continue;
                }

                //
                dp[i][j] = max(dp[i][j-weight[i-1]] + profit[i-1], dp[i-1][j]);
                // i = 2... j = 7...
                //we pciked 3 and 7 when  j=6....
                // dp[i][j] = dp[i][j-weigght[i]] + proft[i]

                //or... 
                // j = 8.... 
                 
            }
        }
        return dp[M][N];
    }
};
