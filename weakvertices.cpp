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
 * Problem Name: Weak Vertices
 * Difficulty: 1.5 (Easy)
 * Categories: Graph
 * Algorithms: 
 */

int main() {
    init_cin();

    while(true) {
        int N;
        cin >> N;
        if(N == -1) break;

        vector<vi> adj(N, vi(N));
        rep(i, 0, N) rep(j, 0, N) cin >> adj[i][j];

        vi weak;

        rep(i, 0, N) { // check if each vertex is weak
            rep(n, 0, N) { if(!adj[i][n]) continue; // for each neighbor
                rep(nn, 0, N) { if(!adj[n][nn]) continue; // each neighbor's neighbor
                    if(adj[nn][i]) goto strong; // found a triangle
                }
            }

            weak.push_back(i);
            strong: continue;
        }

        rep(i, 0, sz(weak)) cout << weak[i] << (i == sz(weak) - 1 ? "\n" : " ");
    }

    return 0;
}
