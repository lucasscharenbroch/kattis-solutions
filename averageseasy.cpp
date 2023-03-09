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
 * Problem Name: Paradox With Averages
 * Difficulty: 2.8 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        int NCS, NEC;
        cin >> NCS >> NEC;

        vi cs_iq(NCS);

        double avg_cs_iq = 0, avg_ec_iq = 0;

        rep(i, 0, NCS) {
            cin >> cs_iq[i];
            avg_cs_iq += cs_iq[i];
        }

        rep(i, 0, NEC) {
            int iq;
            cin >> iq;
            avg_ec_iq += iq;
        }

        avg_cs_iq /= NCS;
        avg_ec_iq /= NEC;

        // find the number of elements in cs_iq below avg_cs_iq and above avg_ec_iq
        int result = 0;
        rep(i, 0, NCS) if(cs_iq[i] < avg_cs_iq && cs_iq[i] > avg_ec_iq) result++;

        cout << result << endl;
    }

    return 0;
}
