class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // min cost to fly every person to a city, st n arrive in each city
        // we decide city a or city b for each person, but we need the minimum cost...

        unordered_set<int> flew;
        vector<pair<int,int>> a_costs;

        for (int i = 0; i < costs.size(); i++){
            a_costs.push_back({costs[i][0],i});
        }

        int total_cost = 0;
        int a_counter = 0;
        int b_counter = 0;

        sort(a_costs.begin(), a_costs.end(), [&](pair<int,int> x, pair<int,int> y) {
            return costs[x.second][0] - costs[x.second][1] <
                   costs[y.second][0] - costs[y.second][1];
        });


        int n = costs.size() / 2;

        for (int i = 0; i < costs.size(); i++){
            int person = a_costs[i].second;

            if (i < n) {
                total_cost += costs[person][0];
            } else {
                total_cost += costs[person][1];
            }
        }

        return total_cost;
    }
};


