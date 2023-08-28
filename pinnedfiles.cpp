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
 * Problem Name: Pinned Files
 * Difficulty: 6.6 (Hard)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int givenP, givenU;
    cin >> givenP >> givenU;
    int N = givenP + givenU;

    vi given(N);
    rep(i, 0, N) cin >> given[i];

    int targetP, targetU;
    cin >> targetP >> targetU;

    vi target(N);
    rep(i, 0, N) cin >> target[i];

    int pp = 0, pu = 0, up = 0, uu = 0;

    vector<pair<bool, bool>> pin_status(N);
    rep(i, 0, N) {
        pin_status[given[i] - 1].first = i < givenP;
        pin_status[target[i] - 1].second = i < targetP;
    }

    rep(i, 0, N) {
        if(pin_status[i].first == 0 && pin_status[i].second == 0) uu++;
        if(pin_status[i].first == 0 && pin_status[i].second == 1) up++;
        if(pin_status[i].first == 1 && pin_status[i].second == 0) pu++;
        if(pin_status[i].first == 1 && pin_status[i].second == 1) pp++;
    }

    int pp_in_rel_order = 0, uu_in_rel_order = 0;

    int i = 0, j = 0;
    while(i < givenP && j < targetP) {
        if(given[i] == target[j]) {
            pp_in_rel_order++;
            i++, j++;
        } else i++;
    }

    i = j = N - 1;
    while(i >= givenP && j >= targetP) {
        if(given[i] == target[j]) {
            uu_in_rel_order++;
            i--, j--;
        } else i--;
    }

    int result = 2 * (pp - pp_in_rel_order) + up +
                 2 * (uu - uu_in_rel_order) + pu;

    cout << result << endl;

    return 0;
}
