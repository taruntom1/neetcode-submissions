class Solution {
   public:
    string encode(vector<string>& strs) {
        string ret;

        for (const auto& s : strs) {
            ret += static_cast<char>(s.size() >> 8);
            ret += static_cast<char>(s.size());
            ret += s;
        }

        return ret;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<string> ret;

        auto it = s.begin();

        while (it != s.end()) {
            int size = (static_cast<unsigned char>(*it++) << 8) | static_cast<unsigned char>(*it++);

            auto next = it + size;
            ret.emplace_back(it, next);
            it = next;
        }

        return ret;
    }
};