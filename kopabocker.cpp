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
 * Problem Name: Buying Books
 * Difficulty: 2.5 (Easy)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;
    vector<vi> prices(M, vi(N, INT_MAX));
    vi fees(M);

    rep(i, 0, M) {
        int K;
        cin >> K >> fees[i];
        rep(j, 0, K) {
            int n;
            cin >> n >> prices[i][--n];
        }
    }

    ll min_cost = INT_MAX;
    ll curr_cost = 0;

    rep(b, 1, 2 << (M + 1)) { // consider all combinations of book stores
        curr_cost = 0;
        rep(i, 0, N) {
            int price = INT_MAX;
            rep(j, 0, M) {
                if(!((b >> j) % 2)) continue; // store not selected
                if(i == 0) curr_cost += fees[j]; // count store fee on first iteration
                price = min(price, prices[j][i]);
            }
            curr_cost += price;
        }
        min_cost = min(min_cost, curr_cost);
    }

    cout << min_cost << endl;

    return 0;
}
