class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int ans = 10, cur = 9;

        for (int i = 2; i <= n && i <= 10; i++) {
            cur *= (11 - i);
            ans += cur;
        }

        return ans;
    }
};