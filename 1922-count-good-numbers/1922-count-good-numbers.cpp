class Solution {
    #define MOD 1000000007

public:

    long long power(long long i, long long n) {
        long long ans = 1;

        while(n > 0) {
            if(n % 2 == 1)
                ans = (ans * i) % MOD;

            i = (i * i) % MOD;
            n = n / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) * power(4, n / 2)) % MOD;
    }
};