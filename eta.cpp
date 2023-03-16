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
 * Problem Name: ETA
 * Difficulty: 4.1 (Medium)
 * Categories: Graph, Math
 * Algorithms: 
 */

int arith_sum(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    init_cin();

    int a, b;
    char ignore_slash;
    cin >> a;
    cin >> ignore_slash;
    cin >> b;

    if(a < b - 1) {
        cout << "impossible" << endl;
        return 0;
    }
    
    // for any graph with b*i nodes and d total distance to node 1,
    // d / b*i is the average (minimal) distance from node 1, and
    // (b*i - 1) / b*i <= d / b*i <= ((b*i-1) + (b*i-2) + ... + 1) / b*i
    // so
    // b*i - 1 <= d <= arith_sum(b*1 - 1)
    //
    // we can use the quadratic growth of the upper bound to grow d until
    // d[i] < a <= d[i + 1],
    // then we can add b more edges to the graph, and move them around such
    // that d[i + 1] = a.

    int i = 1;
    while(a * i > arith_sum(b * i - 1)) i++;
    i--;
    
    ll d = arith_sum(b * i - 1);
    int n = b * i; // number of nodes
    vector<pii> edges;
    rep(j, 1, n) edges.push_back(pii(j, j + 1)); // set up "chain"-shaped graph
                                                 // with b * i (b * i - 1) avg. optimal dist.
    if(i == 0) { // no chain-graph
        n++; // add a single 1-node
        b--; // add 1 less node later
    }

    // add b nodes to the graph, and position them such that d = a * i
    d += b, n += b, i++;
    rep(j, n - b + 1, n + 1) { // choose which edges to add
        if(d == a * i) edges.push_back(pii(1, j));
        else if(a * i - d <= j - 2) {
            edges.push_back(pii(a * i - d + 1, j));
            d = a * i;
        } else {
            edges.push_back(pii(j - 1, j));
            d += j - 2;
        }
    }

    cout << n << " " << sz(edges) << endl;
    rep(j, 0, sz(edges)) {
        cout << edges[j].first << " " << edges[j].second << endl;
    }

    return 0;
}
