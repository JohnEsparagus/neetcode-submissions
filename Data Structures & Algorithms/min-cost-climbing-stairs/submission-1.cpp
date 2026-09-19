class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size() + 1, 0);

        for (int i = 2; i < cost.size() + 1; i++){
            cache[i] = min(cost[i-1] + cache[i-1], cost[i-2] + cache[i-2]);
        }

        return cache[cost.size()];

        
    }
};
