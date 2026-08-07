class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;

        for (int i = 0; i < nums.size(); i++) {
            int d = target - nums[i];
            if (!diff.contains(d)) {
                diff[nums[i]] = i;
                continue;
            }
            return {diff[d], i};
        }
        return {};
    }
};
