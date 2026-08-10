class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        array<bool, 256> check{};
        auto l = s.begin();
        auto r = s.begin();
        int greatest = 0;

        while (r != s.end()) {
            if (!check[*r]) {
                check[*r] = true;
            } else {
                while (*l != *r) {
                    check[*l++] = false;
                }
                l++;
            }

            int len = static_cast<int>(r - l) + 1;
            greatest = max(greatest, len);

            r++;
        }
        return greatest;
    }
};
