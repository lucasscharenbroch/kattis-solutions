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
 * Problem Name: Bazaar
 * Difficulty: 4.7 (Hard)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;
    N /= 2;

    vector<int> goods_a(N), goods_b(N);
    long long score_a = 0, score_b = 0;


    rep(i, 0, N) { cin >> goods_a[i]; score_a += goods_a[i]; }
    rep(i, 0, N) { cin >> goods_b[i]; score_b += goods_b[i]; }

    sort(all(goods_a));
    sort(all(goods_b));

    for(int i = N - 1; i >= 0; i--) {
        // always remove the most expensive good from each player's array, 
        // and add to the scores accordingly.

        score_a += goods_a.size() - 1;
        score_b += upper_bound(all(goods_b), goods_a[i]) - goods_b.begin();
        goods_a.pop_back();


        score_b += goods_b.size() - 1;
        score_a += upper_bound(all(goods_a), goods_b[i]) - goods_a.begin();
        goods_b.pop_back();
    }

    cout << score_a - score_b << endl;

    return 0;
}
