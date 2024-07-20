#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
//该算法可以算出从一个顶点到其余各顶点的最短路径，解决的是有权图中最短路径问题
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    char to;
    int weight;
};

vector<vector<Edge>> createGraph(int n) {
    vector<vector<Edge>> graph(n);
    return graph;
}

void addEdge(vector<vector<Edge>>& graph, char u, char v, int w) {
    graph[u - 'A'].push_back({v, w});
    graph[v - 'A'].push_back({u, w});
}

int dijkstra(const vector<vector<Edge>>& graph, char start, char end) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start - 'A'] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//升序队列
    pq.push({0, start - 'A'});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (const auto& edge : graph[u]) {
            int v = edge.to - 'A';
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end - 'A'];
}

int main() {
    int n, m;
    cout << "请输入城市个数和路径条数" << endl;
        while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<vector<Edge>> graph = createGraph(n);
        vector<char> cityNames(n);
        cout << "请输入城市名称" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> cityNames[i];
        }
        cout << "请依次输入两城市之间的路径" << endl;
            for (int i = 0; i < m; ++i) {
            char start, end;
            int weight;
            cin >> start >> end >> weight;
            addEdge(graph, start, end, weight);
        }
        char start, end;
        cout << "请输入起点和终点" << endl;
        cin >> start >> end;
        int dist = dijkstra(graph, start, end);
        cout << "从城市 " << start << " 到城市 " << end << " 的最短距离为：" << dist << endl;
    }
    return 0;
}