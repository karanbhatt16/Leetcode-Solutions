class ProductOfNumbers {
    vector<long long> a;
    vector<long long> prefix;
    vector<int> zero;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        a.push_back(num);
        long long prev = 1;
        int count = 0;
        if (zero.size() != 0) {
            count = zero[zero.size() - 1];
        }
        if (num == 0) {
            zero.push_back(count + 1);
        } else {
            zero.push_back(count);
        }
        if (prefix.size() != 0) {
            prev = prefix[prefix.size() - 1];
        }
        if (num != 0) {
            prefix.push_back(1LL * num * prev);
        } else {
            prefix.push_back(1);
        }
    }
    
    int getProduct(int k) {
        int n = a.size();
        if (n - k  - 1 < 0) {
            if (zero[n - 1] > 0) return 0;
            return prefix[n - 1];
        }
        if (zero[n - 1] - zero[n - k - 1] > 0) return 0;
        return prefix[n - 1] / prefix[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */