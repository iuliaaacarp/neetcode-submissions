class Solution {
public:

    bool checkFreq(int freqS[128], int freqT[128]) {
        for (int i = 0; i < 128; i++) {
            if (freqS[i] < freqT[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int freqT[128] = {0}, freqS[128] = {0};
        string res = "";
        int lenMin = 1e7;

        if (t.length() > s.length()) {
            return "";
        }

        int left = 0, right = t.length() - 1;
        for (int i = 0; i < t.length(); i++) {
            freqT[t[i]]++;
            freqS[s[i]]++;
        }

        bool allChecked = false;
        while (!allChecked && left <= right) {
            while (!checkFreq(freqS, freqT)) {
                right ++;
                if (right == s.length()) {
                    return res;
                }
                freqS[s[right]]++;
            }

            while (checkFreq(freqS, freqT)) {
                freqS[s[left]]--;
                left ++;
            }

            left --;
            freqS[s[left]]++;

            if (checkFreq(freqS, freqT) && right - left + 1 < lenMin && left <= right) {
                res = "";

                lenMin = right - left + 1;
                for (int i = left; i <= right; i++) {
                    res += s[i];
                }
            }

            freqS[s[left]]--;
            left++;
            right++;
            
            if (right < s.length()) {
                freqS[s[right]]++;
            }

            if (right == s.length()) {
                allChecked = true;
            }
        }
        return res;
    }
};