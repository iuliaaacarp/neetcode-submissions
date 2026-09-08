class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty())
            return "";
        string res;

        for (const string str : strs) {
            res += to_string(str.length());
            res += "#";
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty())
            return {};

        vector<string> res;
        int pos = 0;
        while (pos < s.length()) {
            int size = 0;
            while (s[pos] != '#') {
                size = size * 10 + s[pos] - '0';
                pos++;
            }
            pos ++;
            string oneWord = s.substr(pos, size);
            pos += size;
            res.push_back(oneWord);
        }
        return res;
    }
};