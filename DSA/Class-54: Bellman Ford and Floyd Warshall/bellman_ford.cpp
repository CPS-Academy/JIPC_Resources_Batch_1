#include<bits/stdc++.h>
using namespace std;

int dist[1003];

struct Edge {
    int u, v, weight;
};
vector<Edge> edges;

int main() {

    int N, E;
    cin >> N >> E;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
//        Edge edge(u, v, w);
        Edge edge = {u, v, w};
        edges.push_back(edge);
    }

    int source;
    cin >> source;
    for(int i = 1; i <= N; i++) {
        dist[i] = 100005;
    }
    dist[source] = 0;


    for(int i = 1; i <= N - 1; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;
        if(dist[u] + w < dist[v]) {
            cout << "Negative Cycle Detected!!\n";
            break;
        }
    }

    for(int u = 1; u <= N; u++) {
        cout << u << ": " << dist[u] << '\n';
    }
    cout << '\n';

    return 0;
}

/*
5 7
5 1 -1
5 2 4
1 2 3
1 4 2
1 3 2
3 4 -3
4 1 1
*/
