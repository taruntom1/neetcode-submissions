class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto cmp = [](const int b, const vector<int>& a) {
            return b < a[0];
        };
        auto it = upper_bound(matrix.begin(), matrix.end(), target, cmp);

        if (it != matrix.begin()) {
            --it;
            return binary_search(it->begin(), it->end(), target);
        }
        return false;
    }
};