#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

vector<vector<Edge>> graph;
vector<int> dis;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > dis[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N);
    dis.assign(N, INF);

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        graph[U].emplace_back(V, W);
        graph[V].emplace_back(U, W); // Đồ thị vô hướng, nên cần thêm cả 2 hướng.
    }

    dijkstra(0);

    // Tính tổng khoảng cách từ đỉnh 0 đến tất cả các đỉnh còn lại.
    int total_dis = 0;
    for (int i = 1; i < N; i++) {
        total_dis += dis[i];
    }

    cout << "Khoảng cách ngắn nhất từ đỉnh 0 đến tất cả các đỉnh còn lại: " << total_dis << endl;

    return 0;
}
