class Solution
{
    unordered_map<int, vector<int>> adj;
    int n;
    vector<vector<int>> ans;
    void dfs(int curr, vector<int> &path)
    {
        if (curr == n - 1)
        {
            ans.push_back(path);
            return;
        }
        for (auto ele : adj[curr])
        {
            path.push_back(ele);
            dfs(ele, path);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size();
        for (int i = 0; i < n; i++)
            for (auto ele : graph[i])
                adj[i].push_back(ele);

        vector<int> path;
        path.push_back(0);
        dfs(0, path);
        return ans;
    }
};