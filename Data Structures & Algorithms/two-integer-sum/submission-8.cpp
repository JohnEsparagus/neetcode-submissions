class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //we know whwat to do
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j && nums[i] + nums[j] == target){

                    ans.push_back(min(i,j));
                    ans.push_back(max(i,j));
                    return ans;
                }
            }
        }
        return ans;
    }
};
