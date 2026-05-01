class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while (s[i]==' ') {
            i--;
        }
        int l = i;
        while (s[l]!=' ') {
            if (l==0) break;
            l--;
        }
        if (i==l) return 1;
        return i-l;
    }
};