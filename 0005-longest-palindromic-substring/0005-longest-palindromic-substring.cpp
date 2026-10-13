class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 1;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int l = i, r = j;

                while (l < r && s[l] == s[r])
                    l++, r--;

                if (l >= r && j - i + 1 > len) {
                    start = i;
                    len = j - i + 1;
                }
            }
        }

        return s.substr(start, len);
    }
};