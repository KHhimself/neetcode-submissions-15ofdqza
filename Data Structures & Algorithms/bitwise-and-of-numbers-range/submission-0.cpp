class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int k = 0;
        while (left !=right) {
            left >>= 1;
            right >>= 1;
            k++;
        }
        left <<= k;
        return left;
    }
};