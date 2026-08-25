class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int N = profit.size(), M = capacity;
        vector<vector<int>> dp(N+1, vector<int>(M + 1, 0));
        // fill the dp 
        // what does dp evven hold?? probably the profit atp.

        //exclude if -> alr in cache or out of bounds
        //icnlude if -> include always.

        int res = 0;
        for (int i = 1; i <= profit.size(); i++){
            for (int j = 0 ; j <= capacity; j++){
                if (j < weight[i-1]){
                    dp[i][j] = dp[i-1][j];
                    continue; 
                }
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i-1][j - weight[i-1]]);
            }
        }

        return dp[N][M];
    }
};
