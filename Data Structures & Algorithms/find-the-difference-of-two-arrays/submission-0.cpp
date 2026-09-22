class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_set<int> nums1_set;
        unordered_set<int> nums2_set;
        
        for (int i = 0; i < nums1.size(); i++){
            nums1_set.insert(nums1[i]);

        }
        for (int i = 0; i < nums2.size(); i++){
            nums2_set.insert(nums2[i]);
        }

        for (int num : nums1_set){
            if (nums2_set.find(num) == nums2_set.end()){
                answer[0].push_back(num);
            }
            continue;
        }
        for (int num : nums2_set){
            if (nums1_set.find(num) == nums1_set.end()){
                answer[1].push_back(num);
            }
            continue;
        }

        return answer;




    }
};