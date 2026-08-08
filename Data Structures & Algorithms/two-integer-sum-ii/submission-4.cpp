class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (auto it = numbers.begin(); it != numbers.end(); it++) {
            int diff = target - *it;

            auto it2 = lower_bound(it+1, numbers.end(), diff);
            if (it2 != numbers.end() && *it2 == diff) {
                return {static_cast<int>(it - numbers.begin())+1,
                        static_cast<int>(it2 - numbers.begin())+1};
            }
        }
        return {};
    }
};
