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
 * Problem Name: Firetrucks Are Red
 * Difficulty: 4.4 (Medium)
 * Categories: Graph
 * Algorithms: Union-Find
 */

int find(vi& g, int a) {
    if(g[a] == a) return a;
    return g[a] = find(g, g[a]);
}

void unite(vi& g, int a, int b) {
    int pa = find(g, a), pb = find(g, b);
    g[pa] = pb;
}

int main() {
    init_cin();

    int N;
    cin >> N;

    unordered_set<int> traits;
    unordered_map<int, vi> people_with_trait;

    rep(i, 0, N) {
        int m, t;
        cin >> m;
        rep(j, 0, m) {
            cin >> t;
            people_with_trait[t].push_back(i);
            traits.insert(t);
        }
    }

    // set up union find
    int num_groups = N;
    vi group(N);
    rep(i, 0, N) group[i] = i;
    vector<pair<pii, int>> proof;

    // for each edge, unite the two groups if it doesn't cause a cycle
    for(const int& t : traits) {
        int a = people_with_trait[t][0];
        for(int& b : people_with_trait[t]) {
            if(find(group, a) == find(group, b)) continue;
            unite(group, a, b);
            num_groups--;
            proof.push_back(pair<pii, int>(pii(a + 1, b + 1), t));
        }
    }

    if(num_groups != 1) cout << "impossible" << endl;
    else {
        for(auto& p : proof)
            cout << p.first.first << " " << p.first.second << " " << p.second << endl;
    }

    return 0;
}
