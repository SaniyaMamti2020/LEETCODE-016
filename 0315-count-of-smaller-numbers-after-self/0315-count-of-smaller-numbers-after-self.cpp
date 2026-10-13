class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), temp(n), index(n);

        for (int i = 0; i < n; i++)
            index[i] = i;

        function<void(int, int)> mergeSort = [&](int l, int r) {
            if (l >= r) return;

            int mid = (l + r) / 2;
            mergeSort(l, mid);
            mergeSort(mid + 1, r);

            int i = l, j = mid + 1, k = l, rightSmaller = 0;

            while (i <= mid && j <= r) {
                if (nums[index[j]] < nums[index[i]]) {
                    temp[k++] = index[j++];
                    rightSmaller++;
                } else {
                    ans[index[i]] += rightSmaller;
                    temp[k++] = index[i++];
                }
            }

            while (i <= mid) {
                ans[index[i]] += rightSmaller;
                temp[k++] = index[i++];
            }

            while (j <= r)
                temp[k++] = index[j++];

            for (int p = l; p <= r; p++)
                index[p] = temp[p];
        };

        mergeSort(0, n - 1);
        return ans;
    }
};