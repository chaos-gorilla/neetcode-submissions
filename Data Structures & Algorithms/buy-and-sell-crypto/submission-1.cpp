class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            // if you sold on this day, what is the profit.
            int profit_for_day = prices[i] - buy;
            profit = max(profit_for_day, profit);
        }

        return profit;
    }
};
