#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void init_cin() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

/*
 * Problem Name: Single source shortest path, negative weights
 * Difficulty: 5.0 (Medium)
 * Categories: Graph, Dynamic Programming
 * Algorithms: Bellman-Ford
 */

struct edge {
    int u, v, w;
    edge() { }
};

int main() {
    init_cin();

    int N, M, Q, s;

    while(true) {
        cin >> N >> M >> Q >> s;
        if(!N) break;

        vector<edge> edges(M);
        vector<ll> dist(N, LLONG_MAX);
        dist[s] = 0;

        rep(i, 0, M) cin >> edges[i].u >> edges[i].v >> edges[i].w;

        // Bellman-Ford with (N - 1) iterations to determine shortest costs
        rep(i, 0, N - 1) {
            for(edge& e : edges) {
                if(dist[e.u] == LLONG_MAX || dist[e.v] <= dist[e.u] + e.w) continue;
                dist[e.v] = dist[e.u] + e.w;
            }
        }

        // Another (N - 1) iterations to find which nodes have -Inf dist
        rep(i, 0, N - 1) {
            for(edge& e : edges) {
                if(dist[e.u] != LLONG_MIN && (dist[e.u] == LLONG_MAX ||
                   dist[e.v] <= dist[e.u] + e.w)) continue;
                dist[e.v] = LLONG_MIN;
            }
        }

        rep(i, 0, Q) {
            int x;
            cin >> x;
            cout << (dist[x] == LLONG_MAX ? "Impossible" :
                     dist[x] == LLONG_MIN ? "-Infinity" :
                     to_string(dist[x])) << endl;
        }
    }

    return 0;
}
