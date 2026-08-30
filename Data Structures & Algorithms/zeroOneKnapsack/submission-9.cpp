class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        //get smth to record the progress for every profit and every cap
        int N = profit.size();
        int M = capacity;
        vector<vector<int>> storage(N+1,std::vector<int>(M+1,0));
        // 0-> total element.
        for (int i = 1; i <= N; i++){
            for (int j = 0; j <= M; j++){
                
                //simulate taking
                if (j < weight[i-1]){
                    storage[i][j] = storage[i-1][j];
                    continue;
                }

                //note tkae is...
                storage[i][j] = max(storage[i-1][j],profit[i-1] + storage[i-1][j-weight[i-1]]);

            }
        }
        return storage[N][M];
        
    }
};
