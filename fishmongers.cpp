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
 * Problem Name: Fishmongers
 * Difficulty: 3.7
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    priority_queue<int> weights;
    priority_queue<pii> mongers;

    rep(i, 0, N) {
        int w;
        cin >> w;
        weights.push(w);
    }

    rep(i, 0, M) {
        int x, p;
        cin >> x >> p;
        mongers.push(pii(p, x));
    }

    pii curr_mong = {0, 0};
    ll money = 0;
    while(!weights.empty()) {
        if(curr_mong.second == 0) {
            if(mongers.empty()) break;
            curr_mong = mongers.top(); mongers.pop();
        }

        ll curr_weight = weights.top(); weights.pop();
        money += curr_weight * curr_mong.first;
        curr_mong.second--;
    }

    cout << money << endl;

    return 0;
}
