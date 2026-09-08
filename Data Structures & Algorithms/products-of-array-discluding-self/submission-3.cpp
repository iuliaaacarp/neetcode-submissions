class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int countZero = 0;
        vector<int> result;

        for (auto num : nums) {
            if (num != 0) {
                product *= num;
            }
            else {
                countZero++;
            }
        }

        for (auto num : nums) {
            if (num != 0 && countZero != 0) {
                result.push_back(0);
            }
            else if (num == 0 && countZero != 0) {
                if (countZero == 1) {
                    result.push_back(product);
                }
                else {
                    result.push_back(0);
                }
            }
            else {
                result.push_back(product / num);
            }
        }
        return result;
    }
};