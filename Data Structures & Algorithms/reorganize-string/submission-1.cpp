class Solution {
public:
    string reorganizeString(string s) {
    //bro if rogot ughhh
    // any 2 adjacent are not the same.
    //we record the 1st element, then if 2nd elmeent is not same
    //move pointer to 2nd, and keep going

    //if are same
    //perhaps we can sort the characters
    //what property would exist if characters sorted....
    // if any singlular character count > list.size()/2 return ""; (store in hashmap[0]++; etc)
    //otherwise
    // return any arrangement s.t we push_back or insert different letters

    //convert string into chars
    //how are strings stored, a collection of cahrs with \0
    std::sort(s.begin(), s.end());
    vector<int> freq(26,0);
    for (char c : s){
        freq[c-'a']++;
    }    

    int max_id = std::max_element(freq.begin(), freq.end()) - freq.begin(); //char - 'a'

    if (freq[max_id] > (s.size() + 1) / 2) return "";
    //now we know we can make it, for in some random arrangement or smth 
    int i = 0;

    string res(s.size(), ' ');
    
    while( freq[max_id] >0){
        res[i]='a'+max_id;
        freq[max_id]--;
        i+=2;
    }
    //after this 

    for (int ch = 0; ch < 26; ch++){
        while (freq[ch] > 0){
            if (i >= (int)s.size()){
                i = 1;
            }
            res[i] = 'a' + ch;
            freq[ch]--;
            i+=2;

        }
    }
    return res;

    }
    
};