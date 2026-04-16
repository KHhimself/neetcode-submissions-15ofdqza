class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        long long k = n-1;
        long long bit = 1;

        while (k>0) {
            if ((res&bit)==0) {
                if (k&1) {
                    res |= bit;
                }
                k>>=1;
            }
            bit <<= 1;
        }
        return res;
    }
};