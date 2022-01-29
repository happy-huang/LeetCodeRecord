// 无向图连通分量三种解法

// dfs - stack
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        stack<int> st;
        int ans=0, cur;

        for (int i=0; i<n; ++i) {
            if (visited[i] == 1) continue;
            else {
                ans += 1;
                st.push(i);
                visited[i] = 1;
                while (!st.empty()) {
                    cur = st.top();
                    st.pop();

                    for (int j=0; j<n; ++j) {
                        if (isConnected[cur][j] == 1 && visited[j] == 0) {
                            st.push(j);
                            visited[j] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// bfs - queue
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        queue<int> q;
        int ans=0, cur;

        for (int i=0; i<n; ++i) {
            if (visited[i] == 1) continue;
            else {
                ans += 1;
                q.push(i);
                visited[i] = 1;
                while (!q.empty()) {
                    cur = q.front();
                    q.pop();

                    for (int j=0; j<n; ++j) {
                        if (isConnected[cur][j] == 1 && visited[j] == 0) {
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


// 连通图
class Solution {
public:
    int Find(vector<int> &parent, int i) {
        if (parent[i] != i) {
            parent[i] = Find(parent, parent[i]);
        }
        return parent[i];
    }

    void Union(vector<int> &parent, int i, int j) {
        parent[Find(parent,i)] = Find(parent, j);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        int ans=0;

        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (isConnected[i][j] == 1) {
                    Union(parent, i, j);
                }
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (parent[i] == i) ++ans;
        }
        return ans;
    }
};

