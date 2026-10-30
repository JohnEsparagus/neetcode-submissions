class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //we know whwat to do
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        //instant chcek
        // nums[i] + nums[j] = target
        //target - nums[i] = nums[j]

        // mp[target-nums[i]] =

        for (int i = 0; i < n; i++){
            auto it = mp.find(nums[i]);
            if (it != mp.end()){
                std::pair<const int, int> j = *it;
                ans.push_back(min(i,it->second));
                ans.push_back(max(i,it->second));

            }
            mp[target - nums[i]] = i;

        }
        return ans;
    }
};
