class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (nums[mid] - nums[0] < 0) {
                right = mid - 1;
            }
            else if (nums[nums.size() - 1] - nums[mid] < 0){
                left = mid + 1;
            }
            else {
                return nums[0];
            }
        }
    }
};