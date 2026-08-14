class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis)
    {
        vis[node] = true;

        for (int neighbour : adj[node])
        {
            // Ignore the edge back to parent
            if (neighbour == parent)
                continue;

            // Cycle detected
            if (vis[neighbour])
                return false;

            if (!dfs(neighbour, node, adj, vis))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges)
    {
        // A tree must have exactly n - 1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        // Create adjacency list
        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Check cycle
        if (!dfs(0, -1, adj, vis))
            return false;

        // Check connectivity
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return false;
        }

        return true;
    }
};