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
 * Problem Name: Treehouses
 * Difficulty: 3.6 (Medium)
 * Categories: Graph, MST
 * Algorithms: Kruskal's
 */

int find(vi& g, int i) {
    int p = i;
    while(g[p] != p) p = g[p];
    while(i != p) {
        int tmp = g[i];
        g[i] = p;
        i = tmp;
    }
    return p;
}

void unite(vi& g, int i, int j) {
    int pi = find(g, i), pj = find(g, j);
    g[pi] = pj;
}

int main() {
    init_cin();

    int N, E, P;
    cin >> N >> E >> P;

    vector<pair<double, double>> coords(N);
    vi group(N); // for union-find
    rep(i, 0, N) group[i] = i;

    rep(i, 0, N) cin >> coords[i].first >> coords[i].second;

    // unite first e treehouses
    rep(i, 0, E - 1) unite(group, i, i + 1);

    // unite all existing edges
    rep(i, 0, P) {
        int a, b;
        cin >> a >> b;
        unite(group, a - 1, b - 1);
    }

    vector<pair<double, pii>> edges; // {dist, {id-a, id-b}}
    rep(a, 0, N) rep(b, 0, N) {
        double dx = coords[b].first - coords[a].first;
        double dy = coords[b].second - coords[a].second;
        edges.push_back(pair<double, pii>(sqrt(dx * dx + dy * dy), pii(a, b)));
    }

    sort(all(edges));

    double total_weight = 0; // total edge weight added

    rep(i, 0, N * N) {
        pair<double, pii> curr = edges[i];
        double dist = curr.first;
        int a = curr.second.first, b = curr.second.second;
        if(find(group, a) == find(group, b)) continue;
        unite(group, a, b);
        total_weight += dist;
    }

    cout << total_weight << endl;

    return 0;
}
