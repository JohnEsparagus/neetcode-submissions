class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::set<std::vector<int>> unique_sets;
        std::vector<int> p;
        sort(nums.begin(), nums.end(), std::greater<int>());

    std::function<void(int)> dfs = [&](int x) {
            if (x == int(nums.size())){
                unique_sets.insert(p);
                return;
            }
            p.push_back(nums[x]);
            dfs(x+1);
            p.pop_back();
            dfs(x+1);
        };

        dfs(0);

        return std::vector<std::vector<int>>(unique_sets.begin(), unique_sets.end());
    }
};
