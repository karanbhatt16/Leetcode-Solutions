class Solution {
private:
    bool isprime(int num){
        if (num == 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> factors(int x) {
        vector<int> f;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                f.push_back(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) f.push_back(x);
        return f;
    }
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        vector<int> prime;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            vector<int> f = factors(nums[i]);
            for (int p : f) {
                mp[p].push_back(i);
            }
        }

        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        vis[0] = 1;
        int cnt = 0;
        int flag = 0;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front();
                q.pop();
                if (x == n - 1) return cnt;
                if (x < n - 1 && !vis[x + 1]) {
                    vis[x + 1] = 1;
                    q.push(x + 1);
                }
                if (x > 0 && !vis[x - 1]) {
                    vis[x - 1] = 1;
                    q.push(x - 1);
                }
                if (isprime(nums[x])) {
                    int p = nums[x];
                    for (int nxt : mp[p]) {
                        if (!vis[nxt]) {
                            vis[nxt] = 1;
                            q.push(nxt);
                        }
                    }
                    mp[p].clear();
                }
            }
            cnt++;
        }
        return -1;
    }
};