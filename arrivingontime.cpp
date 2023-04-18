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
 * Problem Name: Arriving on Time
 * Difficulty: 5.6 (Hard)
 * Categories: Graph
 * Algorithms: Dijkstra's
 */

struct edge {
    int u, v, t0, p, d;
    edge() { }
};

int main() {
    init_cin();

    int N, M, S;
    cin >> N >> M >> S;

    vector<edge> edges(M);
    vector<vi> cnx(N);

    rep(i, 0, M)  {
         cin >> edges[i].u >> edges[i].v >> edges[i].t0 >> edges[i].p >> edges[i].d;
         cnx[edges[i].v].push_back(i);
    }

    int s = 0, t = N - 1;

    // dijkstra's from t to s
    priority_queue<pii> q; // {time, node} (maximize time)
    vector<bool> vis(N);
    q.push(pii(S, t));

    while(!q.empty()) {
        auto [time, curr] = q.top(); q.pop();
        if(curr == s) {
            if(time < 0) break; // impossible: time is negative
            cout << time << endl;
            return 0;
        }
        if(vis[curr]) continue;
        vis[curr] = true;

        for(int& edge_id : cnx[curr]) {
            edge& e = edges[edge_id];
            if(vis[e.u]) continue; // neigh is visited
            if(time < e.t0 + e.d) continue; // edge can't be used - too early
            int weight = e.d + ((time - e.t0) - e.d) % e.p;
            // int weight = (time - e.t0) % e.p >= e.d ? (time - e.t0) % e.p : (time - e.t0) % e.p + e.p;
            q.push(pii(time - weight, e.u));
        }
    }

    cout << "impossible" << endl;

    return 0;
}
