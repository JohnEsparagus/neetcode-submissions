class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        //we can compare tickets[k] to others. and add time
        int time = 0;
        for (int i = 0; i < tickets.size(); i++){
            int curr = tickets[i];
            int k_ticks = (i <= k) ? tickets[k] : tickets[k] - 1;
            while (k_ticks > 0 && curr > 0){
                curr--;
                k_ticks--;
                time++;

            }
        }
        return time;
    }
};