class Solution {
public:
    int countDigitOne(int n) {
        long long factor = 1;
        int ans = 0;

        while (factor <= n) {
            long long high = n / (factor * 10);
            long long cur = (n / factor) % 10;
            long long low = n % factor;

            if (cur == 0)
                ans += high * factor;
            else if (cur == 1)
                ans += high * factor + low + 1;
            else
                ans += (high + 1) * factor;

            factor *= 10;
        }

        return ans;
    }
};