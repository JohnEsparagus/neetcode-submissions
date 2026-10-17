class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //rotate array to the rigght by k steps.
        
        k %= nums.size();

        //use 2 pointers, k distance from each ot
        //[[7,5,6,1,2,3,4]
        
        //reversal is split
        //e.g k = 3
        // [5,6,7,1,2,3,4]
        // split at 
        //[7,5,6][],1,2,3,4]
        reverse(nums, 0, nums.size() - 1);

        reverse(nums, 0, k-1);
        reverse(nums, k , nums.size()-1);
    }

    void reverse(vector<int>&a, int l, int r){
        while (l <= r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }
};