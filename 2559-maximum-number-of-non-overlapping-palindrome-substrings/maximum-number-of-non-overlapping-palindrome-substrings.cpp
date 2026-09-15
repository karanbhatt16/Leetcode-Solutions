class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        if (k == 1) return n;
        int last = -1;
        for (int i = 0; i < n - k / 2; i++) {
            // for odd
            int left1 = i - 1;
            int right1 = i + 1;
            int length1 = 1;
            while (left1 >= 0 && right1 < n && left1 > last &&
                   s[left1] == s[right1]) {
                length1 += 2;
                if (length1 >= k) {
                    break;
                }
                left1--;
                right1++;
            }

            // for even
            int left2 = i;
            int right2 = i + 1;
            int length2 = 0;
            while (left2 >= 0 && right2 < n && left2 > last &&
                   s[left2] == s[right2]) {
                length2 += 2;
                if (length2 >= k) {
                    break;
                }
                left2--;
                right2++;
            }

            if (length1 < k && length2 < k) continue;
            
            count++;

            if (length1 >= k && length2 >= k) {
                if (right1 < right2)
                    last = right1;
                else
                    last = right2;
            }

            // Only odd is valid
            else if (length1 >= k) {
                last = right1;
            }

            // Only even is valid
            else {
                last = right2;
            }
        }
        return count;
    }
};