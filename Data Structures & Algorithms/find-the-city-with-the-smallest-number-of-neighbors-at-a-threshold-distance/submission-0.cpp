class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        //djkstras from each city...
        //
        //city with smalleest counts...
        vector<int> ans(n);
        vector<vector<pair<int,int>>> adj(n);

        for (const auto& edge : edges){
            int from = edge[0];
            int to = edge[1];            
            int weight = edge[2];

            adj[from].push_back({weight,to});
            adj[to].push_back({weight, from});
        }

        for (int i = 0; i < n; i++){

            if (adj[i].empty()){
                ans[i] = 0;
                continue;
            }

            std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> qu;
            vector<bool> visited(n);
            qu.push({0,i});
            while (!qu.empty()){
                auto [w,u] = qu.top(); qu.pop();
                if (w > distanceThreshold) break;

                if (visited[u]){continue;}
                visited[u] = true;
                if (u!= i && w <= distanceThreshold){
                    ans[i]++;
                } 
                for (const auto& [curr_w, curr_v] : adj[u]){
                    qu.push({w + curr_w, curr_v});
                }
            }
        }

        int min_idx = 0; 
        for (int i = 1; i < n; ++i) {
            if (ans[i] <= ans[min_idx]) {
                min_idx = i;
            }
        }
        return min_idx;


    }
};
