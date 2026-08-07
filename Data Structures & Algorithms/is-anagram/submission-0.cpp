class Solution {
   public:
    bool isAnagram(string s, string t) {
        array<int, 26> a{}, b{};

        for (char c : s) a[static_cast<size_t>(c) - 'a']++;
        for (char c : t) b[static_cast<size_t>(c) - 'a']++;

        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;
        return true;
    }
};
