class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size()+1, 0);
        // we have a nxn, remember which houses we robbed  too.
        int max_profit = 0;
        int curr_profit = 0;

        if  (nums.size() <= 1){
            return nums[0];
        }
        cache[0] = nums[0];
        cache[1] = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); i++){
            cache[i] = max(nums[i] + cache[i-2],cache[i-1]);

            
        }

        return cache[nums.size()-1];
    }
};
