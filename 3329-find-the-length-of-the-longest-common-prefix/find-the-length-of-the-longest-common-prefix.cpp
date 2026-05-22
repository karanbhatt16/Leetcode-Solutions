class Solution {
private:
    int sizeofnum(int num) {
        int size = 0;
        while (num != 0) {
            num /= 10;
            size++;
        }
        return size;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int i = 0; i < arr1.size(); i++) {
            int num = arr1[i];
            while (num != 0) {
                s.insert(num);
                num = num / 10;
            }
        }
        int maxsize = 0;
        for (int i = 0; i < arr2.size(); i++) {
            int num = arr2[i];
            while (num != 0) {
                if (num < pow(10, maxsize)) break;
                if (s.find(num) != s.end()) {
                    maxsize = max(maxsize, sizeofnum(num));
                    break;
                }
                num /= 10;
            }
        }
        return maxsize;
    }
};