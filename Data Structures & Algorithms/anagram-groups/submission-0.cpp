class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const auto& s : strs) {
            int fq[26] = {0};
            for (int i = 0; i < s.length(); i++)
                fq[s[i] - 'a']++;

            string key = to_string(fq[0]);
            for (int i = 1; i < 26; i++) {
                key += "," + to_string(fq[i]);
            }

            map[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& m : map) {
            result.push_back(m.second);
        }
        return result;
    }
};