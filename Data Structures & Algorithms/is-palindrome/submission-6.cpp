class Solution {
public:
    string transformString(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                res += tolower(s[i]);
            }
            else if (isdigit(s[i])) {
                res += s[i];
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        string st = transformString(s);
        for (int i = 0, j = st.length() - 1; i < j; i++, j--) {
            if (st[i] != st[j]) {
                return false;
            }
        }
        return true;
    }
};