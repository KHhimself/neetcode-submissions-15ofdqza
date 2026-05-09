
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> countOrder(26,0);
        vector<int> countS(26,0);
        string ans = "";

        for (int i=0;i<order.length();i++) {
            countOrder[order[i]-'a']++;
        }
        for (int i=0;i<s.length();i++) {
            countS[s[i]-'a']++;
        }
        for (auto& i:order) {
            while (countS[i-'a']!=0) {
                ans += i;
                countS[i-'a']--;
            }
        }

        for (int i=0;i<26;i++) {
            while (countS[i]!=0) {
                ans += ('a'+i);
                countS[i]--;
            }
        }
        return ans;

    }
};