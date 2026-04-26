class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        for (int i=0;i<firstList.size();i++) {
            for (int j=0;j<secondList.size();j++) {
                if (firstList[i][1]<secondList[j][0]) {
                    break;
                }
                int lo = max(firstList[i][0],secondList[j][0]);
                int hi = min(firstList[i][1],secondList[j][1]);
                if (lo<=hi) {
                    ans.push_back({lo,hi});
                }   
            }
        }
        return ans;
    }
};