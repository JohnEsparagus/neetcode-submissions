class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int product = 1;
            for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0){
                product *=-1;
            } else if (nums[i] > 0){
                product *= 1;
            } else { return 0;}
        }
        return product;
    }
};