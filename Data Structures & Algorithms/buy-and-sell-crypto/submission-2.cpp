class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        auto it_b = prices.begin();
        auto it_s = prices.begin();
        auto it = prices.begin();
        int max_profit = 0;

        while (it != prices.end()) {
            int profit = *it - *it_b;

            auto it2 = it_s;
            while (it2 != it) {
                if (*it2 < *it_b) it_b = it2;
                it2++;
            }

            it_s = it;

            max_profit = (max_profit > (*it_s - *it_b)) ? max_profit : *it_s - *it_b;

            it++;
        }

        return max_profit;
    }
};
