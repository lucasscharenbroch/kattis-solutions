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
 * Problem Name: Reachable Roads
 * Difficulty: 2.1 (Easy)
 * Categories: Graph
 * Algorithms: Union Find
 */

int find(vi& group, int x) {
    return group[x] == x ? x : group[x] = find(group, group[x]);
}

void unite(vi& group, int x, int y) {
    group[find(group, x)] = find(group, y);
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        int M, R;
        cin >> M >> R;

        vi group(M);
        rep(i, 0, M) group[i] = i;

        rep(i, 0, R) {
            int a, b;
            cin >> a >> b;
            unite(group, a, b);
        }

        // count the number of components
        int components = 1;
        rep(i, 0, M) {
            if(find(group, i) != find(group, 0)) {
                unite(group, i, 0);
                components++;
            }
        }

        cout << (components - 1) << endl;
    }

    return 0;
}
