class Solution {
public:
    bool divides(const string& t, const string& s) {
        if (s.size() % t.size() != 0) return false;
        int k = s.size() / t.size();
        string built = "";
        for (int i = 0; i < k; i++) built += t;
        return built == s;
    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        while (n2) {
            int tmp = n1 % n2;
            n1 = n2;
            n2 = tmp;
        }

        string sub1 = str1.substr(0,n1);
        string sub2 = str2.substr(0,n1);

        bool a1 = divides(sub1, str1);
        bool a2 = divides(sub2, str2);
        if (a1&&a2 && (sub1==sub2)) return sub1;
        return "";
    }
};