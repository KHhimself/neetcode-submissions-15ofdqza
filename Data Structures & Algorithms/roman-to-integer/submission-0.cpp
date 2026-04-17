class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;mp['V'] = 5;mp['X'] = 10;mp['L'] = 50;
        mp['C'] = 100;mp['D'] = 500;mp['M'] = 1000;
        int i = 0;
        int ans = 0;
        while (i<s.length()) {
            if (i+1<s.length()) {
                int first = mp[s[i]];
                int second = mp[s[i+1]];
                if (second > first) {
                    ans += (second - first);
                    i += 2;
                }
                else {
                    ans += first;
                    i++;
                }
            }
            else {
                int first = mp[s[i]];
                ans += first;
                i++;
            }
        }
        return ans;
    }
};