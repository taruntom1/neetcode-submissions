class Solution {
   public:
    int climbStairs(int n) {
        int curr = 1;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int k = curr + prev;
            prev = curr;
            curr = k;
        }
        return curr;
    }
};
