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
 * Problem Name: Chopping Wood
 * Difficulty: 3.1 (Medium)
 * Categories: Tree
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi V(N);
    vi counts(N + 1, 0); // counts of occurrences of each node in V.

    rep(i, 0, N) {
        cin >> V[i];
        counts[V[i]]++;
    }

    // we know that a node n becomes a leaf at V[i] where V[i] != n, V[i + 1] != n, ...
    // (because none of its children are ever removed after i => it has no more children)
    // therefore, at each index, we can maintain a heap of available leaf nodes, and always
    // pick the minimal for u[i].

    vi u(N);

    priority_queue<int, vector<int>, greater<int>> leaves;
    rep(i, 1, N + 1) if(!counts[i]) leaves.push(i);

    rep(i, 0, N) {
        if(leaves.empty()) {
            cout << "Error" << endl;
            return 0;
        }

        u[i] = leaves.top(); leaves.pop();
        if(--counts[V[i]] == 0) leaves.push(V[i]);
    }

    rep(i, 0, N) cout << u[i] << endl;

    return 0;
}
