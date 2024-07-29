#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <tuple>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from, to, cap, flow, cost;
    Edge(int from, int to, int cap, int flow, int cost)
        : from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

class MCMF {
public:
    MCMF(int n) : n(n), edges(), G(n), in_queue(n), dist(n), p(n), a(n) {}

    void addEdge(int from, int to, int cap, int cost) {
        edges.emplace_back(from, to, cap, 0, cost);
        edges.emplace_back(to, from, 0, 0, -cost);
        G[from].push_back(edges.size() - 2);
        G[to].push_back(edges.size() - 1);
    }

    tuple<int, int> minCostMaxFlow(int s, int t, int maxFlow) {
        int flow = 0, cost = 0;
        while (flow < maxFlow) {
            fill(dist.begin(), dist.end(), INF);
            fill(a.begin(), a.end(), 0);
            dist[s] = 0;
            a[s] = INF;
            queue<int> Q;
            Q.push(s);
            in_queue[s] = true;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                in_queue[u] = false;
                for (int i : G[u]) {
                    Edge &e = edges[i];
                    if (e.flow < e.cap && dist[e.to] > dist[u] + e.cost) {
                        dist[e.to] = dist[u] + e.cost;
                        p[e.to] = i;
                        a[e.to] = min(a[u], e.cap - e.flow);
                        if (!in_queue[e.to]) {
                            Q.push(e.to);
                            in_queue[e.to] = true;
                        }
                    }
                }
            }
            if (dist[t] == INF) break;
            int d = min(a[t], maxFlow - flow);
            flow += d;
            cost += d * dist[t];
            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += d;
                edges[p[u] ^ 1].flow -= d;
            }
        }
        return {flow, cost};
    }

private:
    int n;
    vector<Edge> edges;
    vector<vector<int>> G;
    vector<bool> in_queue;
    vector<int> dist, p, a;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(k);
    for (int i = 0; i < k; i++) {
        cin >> l[i];
    }
    vector<int> node_weights(n);
    for (int i = 0; i < n; i++) {
        cin >> node_weights[i];
    }
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; // 0-based indexing
        edges[i].second--; // 0-based indexing
    }

    int S = 2 * n, T = 2 * n + 1;
    MCMF mcmf(2 * n + 2);

    for (int i = 0; i < n; i++) {
        mcmf.addEdge(2 * i, 2 * i + 1, node_weights[i], 0);
    }
    for (const auto &e : edges) {
        mcmf.addEdge(2 * e.first + 1, 2 * e.second, 1, 1);
    }
    for (int i = 0; i < n; i++) {
        mcmf.addEdge(S, 2 * i, k, 0);
        mcmf.addEdge(2 * i + 1, T, k, 0);
    }

    auto [flow, cost] = mcmf.minCostMaxFlow(S, T, k);
    cout << "最大点权和: " << -cost << endl;

    return 0;
}