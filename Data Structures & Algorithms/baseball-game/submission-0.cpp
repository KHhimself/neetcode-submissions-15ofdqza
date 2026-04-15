class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for (auto& i:operations) {
            if (i=="C") {
                ans.pop_back();
            }
            else if (i=="D") {
                int n = ans.size();
                ans.push_back(ans[n-1]*2);
            }
            else if (i=="+") {
                int n = ans.size();
                int last = ans[n-1];
                int b = ans[n-2];
                ans.push_back(last+b);
            }
            else {
                int cur = stoi(i);
                ans.push_back(cur);
            }
        }
        int tmp = 0;
        for (int i=0;i<ans.size();i++) {
            tmp += ans[i];
        }
        return tmp;
    }
};