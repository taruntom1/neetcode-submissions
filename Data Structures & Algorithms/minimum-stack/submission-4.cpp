class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(0);
            min = val;
        } else {
            int64_t diff = val - min;
            s.push(diff);
            if (diff < 0) {
                min = val;
            }
        }
    }

    void pop() {
        if(s.empty()) return;

        if (s.top() < 0) {
            min = min - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() <= 0) {
            return min;
        }
        return s.top() + min;
    }

    int getMin() { return min; }

   private:
    stack<int64_t> s;
    int64_t min;
};
