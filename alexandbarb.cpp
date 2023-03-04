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
 * Problem Name: Alex and Barb
 * Difficulty: 3.5 (Medium)
 * Categories: Math
 * Algorithms: 
 */

int main() {
    init_cin();

    int K, M, N;
    cin >> K >> M >> N;

    // Consider a player making a move on a deck with i cards. 
    // If i < M, it's an automatic loss
    // If M <= i <= M + N, the player wins (because they can force the opponent to lose.)
    // If M + N + 1 <= i <= N + 2M, the player loses (because any move will allow the opponent to 
    //                                                apply the above step)
    //
    // This pattern of (N wins, M losses) repeats.
    //
    // So if a player can win with i cards on the deck, they can also win with i + c * (N + M) cards.

    K -= M - 1; // shift K down by (M - 1) so 0 and below is a loss.

    if(K < 0 || (K %= (M + N)) == 0 || K > N) cout << "Barb" << endl;
    else cout << "Alex" << endl;

    return 0;
}
