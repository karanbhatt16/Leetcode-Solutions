class Solution {
private:
    string num;
    int n;
    long long dpn[16][10][10];
    long long dpw[16][10][10];

    pair<long long, long long> solve(int curr, int prev, int prevprev, bool islimit, bool isleadzero) {

        if (curr == n) return {1, 0};

        long long totalnumbers = 0;
        long long totalwav = 0;

        if (!islimit && !isleadzero && prevprev >= 0 && prev >= 0) {
            if (dpn[curr][prev][prevprev] != -1 && dpw[curr][prev][prevprev] != -1) {
                return {dpn[curr][prev][prevprev], dpw[curr][prev][prevprev]};
            }
        }

        int limit = islimit ? (num[curr] - '0') : 9;

        for (int i = 0; i <= limit; i++) {

            bool newleadzero = isleadzero && (i == 0);

            int newprevprev = prev;
            int newprev = newleadzero ? -1 : i;

            auto [remnum, remwav] = solve(curr + 1, newprev, newprevprev, islimit && (i == limit), newleadzero);
            if (!isleadzero && prevprev >= 0 && prev >= 0) {
                bool ispeak = (prev > prevprev) && (prev > i);
                bool isvalley = (prev < prevprev) && (prev < i);
                
                if (ispeak || isvalley) {
                    totalwav += remnum;
                }
            }
            totalnumbers += remnum;
            totalwav += remwav;
        }
        if (!islimit && !isleadzero && prevprev >= 0 && prev >= 0) {
            dpn[curr][prev][prevprev] = totalnumbers;
            dpw[curr][prev][prevprev] = totalwav;
        }
        return {totalnumbers, totalwav};
    }

    long long func(long long number) {
        if (number < 100) {
            return 0;
        }
        memset(dpn, -1, sizeof(dpn));
        memset(dpw, -1, sizeof(dpw));
        num = to_string(number);
        n = num.length();
        auto [totalnumbers, totalwav] = solve(0, -1, -1, true, true);
        return totalwav;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};