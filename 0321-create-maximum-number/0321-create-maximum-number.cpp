class Solution {
public:
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        auto get = [](vector<int> v, int k) {
            vector<int> st;
            int d = v.size() - k;
            for (int x : v) {
                while (d && !st.empty() && st.back() < x)
                    st.pop_back(), d--;
                st.push_back(x);
            }
            st.resize(k);
            return st;
        };

        vector<int> ans;

        for (int i = max(0, k-(int)b.size()); i <= min(k,(int)a.size()); i++) {
            auto x = get(a, i), y = get(b, k-i), cur = vector<int>();

            while (x.size() || y.size()) {
                if (lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()))
                    cur.push_back(x[0]), x.erase(x.begin());
                else
                    cur.push_back(y[0]), y.erase(y.begin());
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};