class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < smallest) {
                smallest = prices[i];
            }

            profit = max(profit, prices[i] - smallest);
        }

        return profit;
    }
};