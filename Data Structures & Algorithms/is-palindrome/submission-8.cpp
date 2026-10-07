class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for (char c : s){
            if (isalnum(c)){
                str+=c;
            }
        }
    for (char &c : str) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
        string reversed(str.rbegin(), str.rend());

        if (reversed==str){
            return true;
        }
        return false;
    }
};
