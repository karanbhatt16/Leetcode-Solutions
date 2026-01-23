class Solution {
public:

    typedef long long ll;

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int badpair = 0;

        vector<ll> temp(n);

        vector<int> prevInd(n);
        vector<int> nextInd(n);

        set<pair<ll, int>> minsum;

        for (int i = 0; i < n; i++) {
            prevInd[i] = i - 1;
            nextInd[i] = i + 1;
            temp[i] = nums[i];
            if(i != n - 1) {
                minsum.insert({nums[i] + nums[i + 1], i});

                if (nums[i] > nums[i + 1]) badpair++;
            }
        }

        int operations = 0;

        while (badpair) {
            operations++;
            auto it = minsum.begin();
            int first = it->second;
            int second = nextInd[first];

            int first_left = prevInd[first];
            int second_right = nextInd[second];

            minsum.erase(begin(minsum));

            if (temp[first] > temp[second]) {
                badpair--;
            }
            // left
            if (first_left >= 0) {
                if (temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second]) {
                    badpair--;
                } else if (temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second]) {
                    badpair++;
                }
            }
            // right
            if (second_right < n) {
                if (temp[second] > temp[second_right] && temp[second_right] >= temp[first] + temp[second]) {
                    badpair--;
                } else if (temp[second] <= temp[second_right] && temp[second_right] < temp[first] + temp[second]) {
                    badpair++;
                }
            }
            
            if (first_left >= 0) {
                minsum.erase({temp[first] + temp[first_left], first_left});
            }
            if (second_right < n) {
                minsum.erase({temp[second] + temp[second_right], second});
            }
            temp[first] += temp[second];
            nextInd[first] = nextInd[second];
            if (first_left >= 0) {
                minsum.insert({temp[first_left] + temp[first], first_left});
            }
            if (second_right < n) {
                minsum.insert({temp[first] + temp[second_right], first});
                prevInd[second_right] = prevInd[second];
            }
        }
        return operations;
    }
};