class Solution {
   public:
    int findMin(vector<int>& nums) {
        auto l = nums.begin();
        auto r = nums.end() - 1;

        while (r > l) {
            auto mid = l + (r - l) / 2;
            if (*mid > *r)
                l = mid + 1;
            else
                r = mid;
        }

        return *l;
    }
};
