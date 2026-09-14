class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left, right;
        left.reserve(height.size());
        right.reserve(height.size());
        left[0] = height[0];
        right[height.size()-  1] = height[height.size() - 1];

        for (int i = 1; i < height.size(); i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int sum = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};