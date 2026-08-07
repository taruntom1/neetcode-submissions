class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ltr, rtl;
        ltr.resize(nums.size());
        rtl.resize(nums.size());

        ltr[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            ltr[i] = ltr[i - 1] * nums[i - 1];
        }

        rtl[nums.size() - 1] = 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            rtl[i] = rtl[i + 1] * nums[i + 1];
        }

        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(rtl[i] * ltr[i]);
        }

        return ret;
    }
};
