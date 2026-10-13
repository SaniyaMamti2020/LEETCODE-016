class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long l = 0, r = 0;

        for (int x : nums) {
            l = max(l, (long long)x);
            r += x;
        }

        while (l < r) {
            long long mid = l + (r - l) / 2;
            int parts = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    parts++;
                    sum = 0;
                }
                sum += x;
            }

            if (parts <= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};