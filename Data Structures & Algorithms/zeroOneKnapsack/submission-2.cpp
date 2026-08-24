class Solution {
private:
    int knapsackRecursive(int index, int capacity, vector<int>& profit, vector<int>& weight,  vector<vector<int>>& cache){
        if (index == weight.size() || capacity == 0){
            return 0;
        }
        //cached??

        if (cache[index][capacity]!=-1){
            return cache[index][capacity];
        }


        //case 1, not included
        int excluded = knapsackRecursive(index + 1, capacity, profit, weight, cache);

        //CASE 0 inclduded.

        if (capacity < weight[index] ){
            return excluded;
        }
        int included = profit[index] + knapsackRecursive(index + 1, capacity - weight[index], profit, weight, cache);


        int maximum = max(included, excluded);
        cache[index][capacity] = maximum;
        return maximum;
    }

public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {

        //cache, check for ir
        //i * cols + j.
        std::vector<std::vector<int>> cache(profit.size(), std::vector<int>(capacity + 1, -1 ));

        return knapsackRecursive(0, capacity, profit, weight, cache);

    }
};
