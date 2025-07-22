#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent, size, depth;
    vector<bool> deleted;
    vector<vector<int>> children;
    int next_node;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        depth.resize(n, 0);
        deleted.resize(n, false);
        children.resize(n); // For keeping track of children of nodes
        next_node = 2;  // The next available node ID (since node 1 is initially present)
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        // Simple find without path compression
        while (u != parent[u]) {
            u = parent[u];
        }
        return u;
    }

    void union_sets(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u != v) {
            // Union by size
            if (size[u] < size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
            depth[v] = depth[u] + 1;  // Update depth of v
        }
    }

    int lca(int u, int v) {
        // Ensure we use the true ancestors of the nodes during LCA query
        u = find(u);
        v = find(v);

        if (depth[u] < depth[v]) swap(u, v);
        
        // Traverse upwards to the same depth
        while (depth[u] > depth[v]) {
            u = parent[u];
        }

        // Now, both nodes are at the same depth
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }

        return u;  // The common ancestor
    }

    void delete_node(int v) {
        deleted[v] = true;
        // Reattach children to the parent
        for (int child : children[v]) {
            // Children should be reattached to the parent of `v`
            union_sets(child, parent[v]);
            // Update the depth of the child after reattachment
            depth[child] = depth[parent[v]] + 1;
        }
        children[v].clear();  // Clear the children of deleted node
    }

    void add_node(int parent_node) {
        int new_node = next_node++;  // Generate new node number
        parent[new_node] = parent_node;  // Attach the new node to the specified parent
        depth[new_node] = depth[parent_node] + 1;
        children[parent_node].push_back(new_node);  // Add to the parent’s children list
    }
};

int main() {
    int q;
    cin >> q;

    DSU dsu(2 * q);  // Since at most `q` nodes will be added and indexed from 2 to q+1.

    // Initially, there is node 1.
    while (q--) {
        char query;
        cin >> query;

        if (query == '+') {
            int v;
            cin >> v;
            dsu.add_node(v);
        } else if (query == '-') {
            int v;
            cin >> v;
            dsu.delete_node(v);
        } else if (query == '?') {
            int u, v;
            cin >> u >> v;

            // If any of the nodes are deleted, we adjust the ancestor
            if (dsu.deleted[u]) u = dsu.find(u);  // Update to the real ancestor
            if (dsu.deleted[v]) v = dsu.find(v);  // Update to the real ancestor

            cout << dsu.lca(u, v) << endl;
        }
    }

    return 0;
}
