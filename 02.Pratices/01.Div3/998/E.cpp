#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;

        DSU dsuF(n), dsuG(n);

        for (int i = 0; i < m1; i++) {
            int u, v;
            cin >> u >> v;
            dsuF.unite(u, v);
        }

        for (int i = 0; i < m2; i++) {
            int u, v;
            cin >> u >> v;
            dsuG.unite(u, v);
        }

        vector<pair<int, int>> operations;

        // Identify representative nodes for each component in G
        vector<int> repG(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            int root = dsuG.find(i);
            if (repG[root] == -1) {
                repG[root] = i;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dsuF.find(i) != dsuF.find(j) && dsuG.find(i) == dsuG.find(j)) {
                    dsuF.unite(i, j);
                    operations.emplace_back(i, j);
                }
            }
        }

        cout << operations.size() << "\n";
        for (auto [u, v] : operations) {
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}