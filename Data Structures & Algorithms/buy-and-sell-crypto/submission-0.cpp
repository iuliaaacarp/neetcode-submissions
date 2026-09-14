class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> left, right;
        left.reserve(prices.size());
        right.reserve(prices.size());

        left[0] = prices[0];
        right[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = 1; i < prices.size(); ++i) {
            left[i] = min (prices[i], left[i - 1]);
        }

        for (int i = prices.size()-2; i >= 0; --i) {
            right[i] = max (prices[i], right[i + 1]);
        }

        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            maxProfit = max(maxProfit,  right[i] - left[i]);
        }
        return maxProfit;
    }
};