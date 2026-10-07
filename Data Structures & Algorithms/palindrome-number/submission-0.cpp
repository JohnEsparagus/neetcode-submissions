class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        string pal = to_string(x);
        string reversed(pal.rbegin(), pal.rend());
        if (pal == reversed){
            return true;
        }
        return false;
    }
};