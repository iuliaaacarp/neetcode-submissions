class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (const auto& num : nums) {
            mp[num]++;
        }

        map<int, vector<int>> res;
        for (const auto& num : mp) {
                res[num.second].push_back(num.first);
            }

        vector<int> topK;
        for (auto it = res.rbegin(); it != res.rend() && topK.size() < k; ++it) {
            for (int number : it->second) {
                topK.push_back(number);
                if (topK.size() == k) {
                    break;
                }
            }
        }
        return topK;
    }
};