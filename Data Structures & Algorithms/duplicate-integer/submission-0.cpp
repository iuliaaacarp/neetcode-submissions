#include <algorithm>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int length = nums.size();
        bool isDup = false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 1 && !isDup; i++){
            if (nums[i] == nums[i + 1])
                isDup = true;
        }
        return isDup;
    }
};