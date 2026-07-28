class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string half = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {

            half.append(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
        }

        string secondHalf = half;
        reverse(secondHalf.begin(), secondHalf.end());

        if (middle != '\0') {
            return half + middle + secondHalf;
        }

        return half + secondHalf;
    }
};