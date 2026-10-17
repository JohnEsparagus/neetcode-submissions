class Solution {
   public:
    int rob(vector<int>& nums) {
        // like a linked list u know

        if (nums.size() == 1){
            return nums[0];
        } else if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> dp1(nums.size()-1, 0);
        vector<int> dp2(nums.size()-1, 0);

        dp1[0] = nums[0];
        dp2[0] = nums[1];

        dp1[1] = max(dp1[0], nums[1]);
        dp2[1] = max(dp2[0], nums[2]);

        //[2,9,8,3,6]
        //[2,9,8,3] or [9,8,3,6];


        // for all starting points, evaluate best?

        for (int i = 2; i < nums.size() - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            dp2[i] = max(dp2[i - 1], dp2[ i - 2]+nums[i+1]);
        }
        return max(dp1[nums.size()-2], dp2[nums.size()-2]);
    }
};