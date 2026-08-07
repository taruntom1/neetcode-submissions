class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;

        for (int i = 0; i < nums.size(); i++) {
            int d = target - nums[i];
            auto it = diff.find(d);
            if (it != diff.end()) {
                return {it->second, i};
            }
            diff[nums[i]] = i;
        }
        return {};
    }
};
