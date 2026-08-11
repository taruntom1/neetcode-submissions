class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        auto l = heights.begin();
        auto r = heights.end() - 1;

        while (r > l) {
            maxArea = max(maxArea, getArea(l, r));
            if (*r > *l)
                l++;
            else
                r--;
        }

        return maxArea;
    }

    int getArea(vector<int>::iterator a, vector<int>::iterator b) {
        return min(*a, *b) * static_cast<int>(b - a);
    }
};
