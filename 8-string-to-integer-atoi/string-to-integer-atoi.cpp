class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            i++;
            neg = true;
        }
        if (!neg && s[i] == '+') i++;
        long long num = 0;
        while (i < s.length()) {
            if (s[i] < '0' || s[i] > '9') break;
            num = num * 10 + (s[i] - '0');
            i++;
            if (neg && -num < -(1LL << 31)) return -(1LL << 31);
            if (!neg && num > (1LL << 31) - 1) return (1LL << 31) - 1;
        }
        if (neg) {
            if (-num < -(1LL << 31)) return -(1 << 31);
            return -num;
        } else {
            if (num > (1LL << 31) - 1) return (1LL << 31) - 1;
            return num;
        }
        return num;
    }
};