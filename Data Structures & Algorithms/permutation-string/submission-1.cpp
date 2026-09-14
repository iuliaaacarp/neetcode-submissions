class Solution {
public:

    bool checkFreq(int freqS1[26], int freqS2[26]) {
        for (int i = 0; i < 26; i++) {
            if (freqS2[i] < freqS1[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freqS1[26] = {0}, freqS2[26] = {0};

        if (s1.length() > s2.length()) {
            return false;
        }

        int left = 0, right = s1.length() - 1;
        for (int i = 0; i < s1.length(); i++) {
            freqS1[s1[i] - 'a']++;
            freqS2[s2[i] - 'a']++;
        }

        while (right < s2.length()) {
            if (checkFreq(freqS1, freqS2)) {
                return true;
            }
            freqS2[s2[left] - 'a']--;

            left++;
            right++;

            freqS2[s2[right] - 'a']++;
        }
        return false;
    }
};