class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target == matrix[0][0]) return true;
        int row = 1;
        while (row < matrix.size() && matrix[row][0] <= target){
            row ++;
        }
        if (target < matrix[0][0] || (row > matrix.size() && matrix.size() > 1)) {
            return false;
        }
        int left = 0, right = matrix[0].size() - 1;
        row--;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) {
                return true;
            }
            if (matrix[row][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};
