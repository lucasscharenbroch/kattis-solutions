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
 * Problem Name: Arctic Network
 * Difficulty: 3.9 (Medium)
 * Categories: Graph, Greedy
 * Algorithms: Kruskal's
 */

int find(vi& group, int id) {
    return group[id] == id ? id : group[id] = find(group, group[id]);
}

void unite(vi& group, int a, int b) {
    int pa = find(group, a), pb = find(group, b);
    group[pa] = pb;
}

int main() {
    // init_cin();

    int T;
    cin >> T;

    while(T--) {
        int S, P;
        cin >> S >> P;

        vector<pii> coords(P);

        rep(i, 0, P) cin >> coords[i].first >> coords[i].second;

        vector<pair<double, pii>> edges;
        rep(i, 0, P) rep(j, 0, P) {
            double dx = coords[i].first - coords[j].first;
            double dy = coords[i].second - coords[j].second;

            edges.push_back(pair<double, pii>(sqrt(dx * dx + dy * dy), pii(i, j)));
        }

        sort(all(edges));

        vi group(P);
        rep(i, 0, P) group[i] = i;

        double largest_edge = 0;
        int num_comp = P;

        for(auto& e : edges) {
            if(num_comp == S) break;
            int a = e.second.first, b = e.second.second;
            largest_edge = e.first;

            if(find(group, a) == find(group, b)) continue;
            unite(group, a, b);
            num_comp--;
        }

        printf("%.2f\n", largest_edge);
    }

    return 0;
}
