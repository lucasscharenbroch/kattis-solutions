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
 * Problem Name: 1-d Frogger (Easy)
 * Difficulty: 4.1 (Medium)
 * Categories: Graph
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, S, M;
    cin >> N >> S >> M;
    S--; // adjust to 0-indexing

    vi board(N);
    vector<bool> vis(N);
    rep(i, 0, N) cin >> board[i];

    int curr = S;
    int h = 0;

    while(0 <= curr && curr < N) {
        if(board[curr] == M) { cout << "magic\n"; break; }
        if(vis[curr]) { cout << "cycle\n"; break; }

        vis[curr] = true;
        curr += board[curr];
        h++;
    }

    if(curr < 0) cout << "left\n";
    else if(curr >= N) cout << "right\n";

    cout << h << endl;

    return 0;
}
