class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {

        int M = profit.size();
        int N = capacity;
        std::vector<std::vector<int>> dp(M+1,std::vector<int>(N + 1, 0));

        for (int i = 1; i < profit.size() + 1; i++){
            for (int j = 0; j <= capacity; j++){        
                //dont increment index  so...
                //while loop?
                if (weight[i - 1] > j){
                    dp[i][j] = dp[i - 1][j]; 
                    continue;
                }

                //include
            
                dp[i][j] = max(
    dp[i][j - weight[i - 1]] + profit[i -1],
    dp[i - 1][j]
);

                // then we want to redo this... till weight[i] < capacity;

            }
        }
    return dp[M][N];

    }
};
