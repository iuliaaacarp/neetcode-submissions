class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0, res = 0;

        for (int right = 0; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};