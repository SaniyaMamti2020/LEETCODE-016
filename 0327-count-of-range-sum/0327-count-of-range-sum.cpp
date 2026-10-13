class Solution {
public:
    long long mergeSort(vector<long long>& pre, int l, int r,
                        long long lower, long long upper) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;
        long long count = mergeSort(pre, l, mid, lower, upper)
                        + mergeSort(pre, mid + 1, r, lower, upper);

        int j = mid + 1, k = mid + 1;

        for (int i = l; i <= mid; i++) {
            while (j <= r && pre[j] - pre[i] < lower)
                j++;

            while (k <= r && pre[k] - pre[i] <= upper)
                k++;

            count += k - j;
        }

        vector<long long> temp;
        int i = l;
        j = mid + 1;

        while (i <= mid && j <= r) {
            if (pre[i] <= pre[j])
                temp.push_back(pre[i++]);
            else
                temp.push_back(pre[j++]);
        }

        while (i <= mid) temp.push_back(pre[i++]);
        while (j <= r) temp.push_back(pre[j++]);

        for (int x = 0; x < temp.size(); x++)
            pre[l + x] = temp[x];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        return (int)mergeSort(pre, 0, n, lower, upper);
    }
};