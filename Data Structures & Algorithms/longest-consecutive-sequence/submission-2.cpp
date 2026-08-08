class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> s(nums.begin(), nums.end());
        vector<int> n(s.begin(), s.end());

        int greatest = 0;
        int curr_count = 1;

        for (auto it = n.begin()+1; it != n.end(); it++) {
            if (*(it - 1) != *it - 1) {
                greatest = max(greatest, curr_count);
                curr_count = 1;
            } else {
                curr_count++;
            }
        }

        greatest = max(greatest, curr_count);

        return greatest;
    }
};
