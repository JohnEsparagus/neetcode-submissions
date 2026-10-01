class TimeMap {
private:

        unordered_map<std::string,std::vector<std::pair<int, std::string>>> store; 
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if (!store.count(key)) return "";  


        int l = 0;
        auto& inner = store[key];
        int r = inner.size()-1;

        string result = "";

        while (l <= r){
            int m = l + (r-l)/2;

            if (inner[m].first <= timestamp){
                result = inner[m].second;
                l = m + 1;
                
            } else {
                r = m - 1;
            }

        }
        return result;
    }

};
