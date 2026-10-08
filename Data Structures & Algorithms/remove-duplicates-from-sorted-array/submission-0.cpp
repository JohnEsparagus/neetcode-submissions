class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> mp;

        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i])!=mp.end()){
                mp[nums[i]] = true;
            }
            if (mp[nums[i]]){
                nums.erase(nums.begin() + i); //shifts element lieft
                i--;
            }

        }
        return nums.size();
    }
};