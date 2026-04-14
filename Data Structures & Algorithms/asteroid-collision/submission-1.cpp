class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; 
        for (int i=0;i<asteroids.size();i++) {
            if (asteroids[i]>0) {
                st.push(asteroids[i]);
            }
            else {
                bool survived = true;
                while (!st.empty() && st.top() > 0) {
                    if (st.top() > abs(asteroids[i])) {
                        // 正向贏，負向死
                        survived = false;
                        break;
                    } else if (st.top() == abs(asteroids[i])) {
                        // 同歸於盡
                        st.pop();
                        survived = false;
                        break;
                    } else {
                        // 正向死，繼續往下撞
                        st.pop();
                    }
                }
                if (survived) st.push(asteroids[i]);
            }
        }
          vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
        
    }
};