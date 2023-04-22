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
 * Problem Name: Island Hopping
 * Difficulty: 2.6 (Easy)
 * Categories: Graph, Minimum Spanning Tree
 * Algorithms: Kruskal's
 */

int find(vi& group, int x) {
    return group[x] < 0 ? x : group[x] = find(group, group[x]);
}

void unite(vi& group, int a, int b) {
    a = find(group, a), b = find(group, b);
    if(group[a] > group[b]) swap(a, b);
    group[a] += group[b];
    group[b] = a;
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        int M;
        cin >> M;

        vector<pair<double, double>> coords(M);
        vi group(M, -1);

        rep(i, 0, M) cin >> coords[i].first >> coords[i].second;

        vector<pair<double, pii>> edges;

        rep(i, 0, M) rep(j, 0, M) {
            double dx = coords[i].first - coords[j].first, dy = coords[i].second - coords[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            edges.push_back(pair<double, pii>(dist, pii(i, j)));
        }

        sort(all(edges));

        double result = 0;

        rep(i, 0, sz(edges)) {
            pii& ei = edges[i].second;
            if(find(group, ei.first) == find(group, ei.second)) continue;
            unite(group, ei.first, ei.second);
            result += edges[i].first;
        }

        cout << setprecision(15) << result << endl;
    }

    return 0;
}
