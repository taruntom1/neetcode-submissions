class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it > 0) break;
            if (it != nums.begin() && *it == *(it - 1)) continue;
            auto p = twoSum(it + 1, nums.end(), *it);
            ret.insert(ret.end(), p.begin(), p.end());
        }

        return ret;
    }

    vector<vector<int>> twoSum(vector<int>::iterator l, vector<int>::iterator r, int n) {
        vector<vector<int>> ret;

        while (r > l) {
            int k = -1 * n - *l;
            auto it = lower_bound(l + 1, r, k);

            if (it != r) {
                if (*it == k) ret.push_back({n, *l, k});
                r = it;
            }
            l++;
        }

        return ret;
    }
};
