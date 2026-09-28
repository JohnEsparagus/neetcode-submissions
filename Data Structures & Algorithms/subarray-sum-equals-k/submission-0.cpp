class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //sub arrays equal to k, contiguous....

        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;
        int curSum = 0, ans = 0;

        for (int num : nums){
            curSum += num;
            ans += prefixCount[curSum - k];
            prefixCount[curSum]++;

        }

        return ans;

    }
};