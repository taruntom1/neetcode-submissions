class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (int i : nums) {
            auto it = m.find(i);
            if (it == m.end())
                m[i] = 1;
            else
                m[i]++;
        }
        vector<pair<int, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(),
             [](const pair<int, int> a, const pair<int, int> b) { return b.second < a.second; });

        vector<int> ret;

        for (int i = 0; i < k; i++) ret.push_back(v[i].first);

        return ret;
    }
};
