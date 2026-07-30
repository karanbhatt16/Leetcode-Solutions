class Solution {
public:
    int minimumPushes(string word) {
        int length1 = word.length() / 8;
        int length2 = word.length() % 8;
        return (length1 * (length1 + 1) / 2) * 8 + length2 * (length1 + 1);
    }
};