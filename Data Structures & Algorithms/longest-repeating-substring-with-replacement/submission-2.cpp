class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> chars(s.begin(), s.end());

        int maxLen = 0;
        for (auto c : chars) {
            int left = 0, cnt = 0;
            for (int right = 0; right < s.size(); ++right) {
                if (s[right] == c) cnt++;
                while ((right - left + 1) - cnt > k) {
                    if (s[left] == c) cnt--;
                    left ++;
                }
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};