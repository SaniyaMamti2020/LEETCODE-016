class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;

        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]}); // start
            events.push_back({b[1], b[2]});  // end
        }

        sort(events.begin(), events.end());

        multiset<int> heights = {0};
        vector<vector<int>> ans;
        int prev = 0;

        for (auto [x, h] : events) {
            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));

            int cur = *heights.rbegin();

            if (cur != prev) {
                ans.push_back({x, cur});
                prev = cur;
            }
        }

        return ans;
    }
};