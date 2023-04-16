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
 * Problem Name: The Dragon of Loowater
 * Difficulty: 2.7 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    while(true) {
        int N, M;
        cin >> N >> M;
        if(!N) break;

        vi diam(N);
        rep(i, 0, N) cin >> diam[i];

        vi height(M);
        rep(i, 0, M) cin >> height[i];

        sort(all(height));
        sort(all(diam));

        int cost = 0;
        int h = 0; // current index in height

        rep(i, 0, sz(diam)) {
            while(h < sz(height) && height[h] < diam[i]) h++;
            if(h == sz(height)) goto doomed;
            cost += height[h++];
        }

        cout << cost << endl;
        continue;

        doomed: cout << "Loowater is doomed!" << endl;
    }

    return 0;
}
