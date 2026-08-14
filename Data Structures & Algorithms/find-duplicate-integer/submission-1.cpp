class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        auto f = 0;
        auto s = 0;

        while (true) {
            f = nums[nums[f]];
            s = nums[s];
            if (nums[f] == nums[s]) break;
        }

        int s2 = 0;
        while (true) {
            s = nums[s];
            s2 = nums[s2];

            if (s == s2) return s;
        }
    }
};
