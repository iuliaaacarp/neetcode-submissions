class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqS[26] = {0}, freqT[26] = {0};

        for (int i = 0; i < s.length(); i++){
            int val = s[i] - 'a';
            freqS[val] ++;
        }

        for (int i = 0; i < t.length(); i++){
            int val = t[i] - 'a';
            freqT[val] ++;
        }

        bool isAnagram = true;
        for (int i = 0; i < 26 && isAnagram; i++)
            if (freqS[i] != freqT[i])
                isAnagram = false;

        return isAnagram;
    }
};