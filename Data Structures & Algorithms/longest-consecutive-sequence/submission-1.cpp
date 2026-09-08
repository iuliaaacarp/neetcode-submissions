class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        int curr = 0, streak = 0, i = 0, result = 0;
        sort(nums.begin(), nums.end());

        while (i < nums.size()) {
            if (curr != nums[i]) {
                curr = nums[i];
                streak = 0;
            }
            while (i < nums.size() && curr == nums[i]) {
                i++;
            }
            streak++;
            curr++;
            result = max (result, streak);
        }
        return result;
    }
};