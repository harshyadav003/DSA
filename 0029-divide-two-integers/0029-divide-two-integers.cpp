
class Solution {
public:
    int divide(int dd, int dr) {//dd= dividend, dr= divisor
        if(dd == dr) return 1;

        bool sign = true; // +ve

        if(dd >= 0 && dr < 0) sign = false;
        if(dd < 0 && dr > 0) sign = false;

        long long n = abs((long long)dd);
        long long d = abs((long long)dr);
        long long ans = 0;

        while(n >= d) {
            long long cnt = 0;

            while(n >= (d << (cnt + 1))) cnt++;

            ans += (1LL << cnt);

            n = n - (d << cnt);
        }

        if(ans >= (1LL << 31) && sign == true) return INT_MAX;
        if(ans >= (1LL << 31) && sign == false) return INT_MIN;

        return sign ? ans : -ans;
    }
};

