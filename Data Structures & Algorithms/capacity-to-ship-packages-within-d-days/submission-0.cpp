class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //what can we do brute force??
        if (weights.empty() ){
            return -1;
        }

        //max it would need is days
        //min it would need is according to min element
        int  n = weights.size();
        int curr_sum = 0;
        int largest = *std::max_element(weights.begin(), weights.end());
        //all potential is the sum of weights,  and max element
        for (int i =0; i < n; i++){
            curr_sum+=weights[i];
        }        


        int l = largest; int r = curr_sum;
        int i = 0;

        int res = curr_sum;
        while (l <= r){
            int m = l + (r-l)/2;
            if (can_we_fit_it(weights,m,days) != -1){
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }

        }
        return res;


    }

    int can_we_fit_it(vector<int>& weights, int weight,int days){
        int out = 1;
        int curr_sum = 0;
        for (int i = 0; i < weights.size(); i++){
            if (weights[i] > weight){
                return -1;
            }

            if (curr_sum + weights[i] > weight){
                out++;
                curr_sum = 0;
            }

            curr_sum += weights[i];
        }
        if (out > days){
            return -1;
        }
        return out;
    }
};