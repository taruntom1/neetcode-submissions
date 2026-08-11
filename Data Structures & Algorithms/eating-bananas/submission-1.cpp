class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *max_element(piles.begin(), piles.end());
        int lower = 1;

        while (upper >= lower) {
            int r = lower + (upper - lower) / 2;
            int f_time = finishTime(piles, r);
            cout << r << " " << f_time << endl;
            // if (f_time == h)
            //     return r;
            if (f_time > h)
                lower = r + 1;
            else
                upper = r - 1;
        }
        return lower;
    }

    int finishTime(vector<int>& piles, int r) {
        int time = 0;
        for (int i : piles) {
            time += ceil(static_cast<double>(i) / r);
        }
        return time;
    }
};
