class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> best_buy(prices.size());
        vector<int> best_sell(prices.size());

        int n = prices.size();
        best_buy[0] = prices[0];
        best_sell[n - 1] = prices[n - 1];

        for (int i = 1; i < n; i++) {
            best_buy[i] = min(best_buy[i - 1], prices[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            best_sell[i] = max(best_sell[i + 1], prices[i]);
        }

        int max_profit = 0;
        for (int i = 0; i < n; i++) {
            max_profit = max(best_sell[i] - best_buy[i], max_profit);
        }

        return max_profit;
    }
};
