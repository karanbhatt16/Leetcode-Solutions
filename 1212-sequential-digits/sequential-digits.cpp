class Solution {
private:
    int digits(int n) {
        int count = 0;
        while (n != 0) {
            n /= 10;
            count++;
        }
        return count;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int a = digits(low);
        int b = digits(high);
        vector<int> ans;
        for (int i = a; i <= b; i++) {
            for (int x = 1; x <= 10 - i; x++) {
                int num = 0;
                int k = x;
                for (int j = 0; j < i; j++) {
                    num = num * 10 + k;
                    k++;
                }
                if (num >= low && num <= high) ans.push_back(num);
                else if (num > high) break;
            }
        }
        return ans;
    }
};