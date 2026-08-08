class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& t : tokens) {
            if (isOperator(t)) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(operate(b, a, t[0]));
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }

    bool isOperator(string& c) {
        if (c == "+" || c == "-" || c == "*" || c == "/") return true;
        return false;
    }

    int operate(int a, int b, char c) {
        switch (c) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    }
};
