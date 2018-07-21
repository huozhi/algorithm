class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        };
        typedef priority_queue<int, vector<pair<int, int>>, decltype(cmp)> pq_t;
        pq_t que(cmp);
        unordered_map<int, int> m;
        for (auto val : nums) m[val]++;
        for (auto pair : m) que.push(pair);
        vector<int> res;
        while (k--) {
            pair<int, int> top = que.top();
            res.push_back(top.first);
            que.pop();
        }
        return res;
    }
};
