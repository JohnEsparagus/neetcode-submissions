class Solution {
public:
    string removeKdigits(string num, int k) {
//2 adjacent integers left to right
        string result;
        int n = num.length();
        for (int i = 0; i < n; i++){
            while (k!=0 && !result.empty() && num[i] < result.back()){
               result.pop_back();
               k--;
            }
            result.push_back(num[i]);
        }

        while (k!=0){
            result.pop_back();
            k--;
        }
        size_t first = result.find_first_not_of('0');
        return first == string::npos ? "0" : result.substr(first);
    }
};
