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
 * Problem Name: Kayaking Trip
 * Difficulty: 3.9 (Medium)
 * Categories: Greedy
 * Algorithms: Binary Search
 */

ll B, N, E, SB, SN, SE;

// checks if kayaks can be filled with a minimum speed of $mid
bool is_fesible(vector<ll>& kayaks, ll mid) {
    int b = B, n = N, e = E;

    for(ll k : kayaks) {
        // use the least-experienced combination that is sufficient
        if((SB + SB) * k >= mid && b >= 2) b -= 2;
        else if((SB + SN) * k >= mid && b && n) b--, n--;
        else if((SN + SN) * k >= mid && n >= 2 || // (SN + SN) or (SB + SE) may be next cheapest:
                (SB + SE) * k >= mid && b && e) { // if either is possible, take the lesser
            if(!b || !e || (SB + SE) * k < mid) n -= 2;
            else if(n < 2 || (SN + SN) * k < mid) b--, e--;
            else if((SN + SN) < (SB + SE)) n -= 2;
            else b--, e--;
        }
        else if((SN + SE) * k >= mid && n && e) n--, e--;
        else if((SE + SE) * k >= mid && e >= 2) e -= 2;
        else return false;
    }

    return true;
}

int main() {
    init_cin();

    cin >> B >> N >> E >> SB >> SN >> SE;

    vector<ll> kayaks((B + N + E) / 2);
    for(ll& k : kayaks) cin >> k;

    sort(all(kayaks));
    reverse(all(kayaks));

    // binary-search-the-answer
    ll low = 0, high = 1e5 * 2e3;
    while(low < high) {
        ll mid = (low + high + 1) / 2;
        if(is_fesible(kayaks, mid)) low = mid;
        else high = mid - 1;
    }

    cout << low << endl;

    return 0;
}
