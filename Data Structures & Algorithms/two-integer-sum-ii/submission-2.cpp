class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1, r1, r2;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                r1 = i + 1;
                r2 = j + 1;
                break;
            }
            if (numbers[i] + numbers[j] < target) {
                i++;
            }
            else if (numbers[i] + numbers[j] > target) {
                j--;
            }
        }
        return {r1, r2};
    }
};