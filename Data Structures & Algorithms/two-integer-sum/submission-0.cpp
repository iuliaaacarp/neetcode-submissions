class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool isValid = false;
        vector <int> sol;
        for (int i = 0; i < nums.size() - 1 && !isValid; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target){
                    isValid = true;
                    sol.push_back(i);
                    sol.push_back(j);
                }
        return sol;
    }
};