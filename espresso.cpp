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
 * Problem Name: Espresso!
 * Difficulty: 2.0 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, S;
    cin >> N >> S;

    int refills = 0, tank = S;

    rep(i, 0, N) {
        string s;
        cin >> s;

        int req = (s[0] - '0') + (s.size() == 2);

        if(tank < req) tank = S, refills++;
        tank -= req;
    }

    cout << refills << endl;

    return 0;
}
