class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (isOpening(c))
                st.push(c);
            else if (!st.empty() && closing(st.top()) == c) {
                st.pop();
            } else
                return false;
        }
        return st.empty();
    }

    bool isOpening(char c) {
        switch (c) {
            case '{':
            case '[':
            case '(':
                return true;
            default:
                return false;
        }
    }

    char closing(char c) {
        switch (c) {
            case '{':
                return '}';
            case '[':
                return ']';
            case '(':
                return ')';
            default:
                return 0;
        }
    }
};
