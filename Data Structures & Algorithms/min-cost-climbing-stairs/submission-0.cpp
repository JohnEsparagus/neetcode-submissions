class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> nums(cost.size()+1,0);
        //nnums is the min cost for each floor as we go.

        for (int i = 2; i < cost.size()+1; i++){
            //either step 1 or step 2, either way pay the cost...
            nums[i]= min(nums[i-1]+cost[i-1], nums[i-2] + cost[i-2]);
        }

        return nums[nums.size()-1];

    }
};
