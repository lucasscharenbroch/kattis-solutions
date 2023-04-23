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
 * Problem Name: Lost Map
 * Difficulty: 2.0 (Easy)
 * Categories: Graph, Minimum Spanning Tree
 * Algorithms: Kruskal's
 */

int find(vi& group, int x) {
    return group[x] == x ? x : group[x] = find(group, group[x]);
}

void unite(vi& group, int a, int b) {
    a = find(group, a), b = find(group, b);
    group[a] = b;
}

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<vi> dist(N, vi(N));
    vector<pair<double, pii>> q;
    vi group(N); rep(i, 0, N) group[i] = i;

    rep(i, 0, N) rep(j, 0, N) {
        cin >> dist[i][j];
        if(i != j) q.push_back(pair<double, pii>(dist[i][j], pii(i, j)));
    }

    vector<pii> edges;

    // sort q by distance: if two nodes are unconnected after adding all edges
    // of weight less than their distance, there must be an edges between the two

    sort(all(q));

    for(auto [d, e] : q)
        if(find(group, e.first) != find(group, e.second)) {
            edges.push_back(pii(e.first, e.second));
            unite(group, e.first, e.second);
        }

    for(pii& e : edges) cout << (e.first + 1) << " " << (e.second + 1) << endl;

    return 0;
}
