class Solution {
public:
    int findLucky(vector<int>& arr) {
        //freq == val
        int largest = -1;
        unordered_map<int,int> mp;
        for (int i : arr){
            mp[i]++;
        }

        for (auto& [val, freq] : mp){
            if (val == freq){
                largest = max(largest,val);
            }
        }
        return largest;
    }
};