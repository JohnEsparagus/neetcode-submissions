class Solution {
public:
    int climbStairs(int n) {
        // climb with either 1 or 2 steps

        //as we climb, we can explore possibiltiies like a tree
        //  store each member of this 'tree' in a vector...

        //only if it adds up to n, is it valid.
        int times = 0;
        vector<int> memo(n+1,-1);
        times += helper(n, memo);
        return times;

    }

    int helper(int n, vector<int>& memo){
        if (n==0){
            return 1;
        }
        if (memo[n] != -1) return memo[n];

        if (n<=2){
            return n; //choose to explore 2 steps
        }
    
        memo[n] = helper(n-1,memo) + helper(n-2,memo);
        return memo[n]; //choose to explore 1 step
    }
    //n==2
};
