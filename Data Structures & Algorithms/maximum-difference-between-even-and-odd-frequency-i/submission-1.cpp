class Solution {
public:
    int maxDifference(string s) {
        vector<int> vec(26,0);
        for (char c : s){
            vec[c-'a']++;
        }

        sort(vec.begin(), vec.end());
        int max_odd = 0;
        int min_even = INT_MAX;
        for (int i = 0; i < 26; i++){
            if (vec[i]!=0  && vec[i] %  2 ==  0 ){
                min_even = min(min_even,vec[i]);
            } else {
                max_odd = max(max_odd, vec[i]);
            }
        }

        return max_odd - min_even;
    }
};