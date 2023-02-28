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
 * Problem Name: UTF-8
 * Difficulty: 2.0 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int t4 = 0;

    int num_10 = 0;

    while(N--) {
        string byte;

        cin >> byte;

        if(num_10) {
            if(byte[0] != '1' || byte[1] != '0') {
                cout << "invalid" << endl;
                return 0;
            }
            num_10--;
            continue;
        }

        if(byte[0] == '1' && byte[1] == '0') {
            cout << "invalid" << endl;
            return 0;
        }

        if(byte[0] == '0') t1++;
        else if(byte[2] == '0') num_10 = 1, t2++;
        else if(byte[3] == '0') num_10 = 2, t3++;
        else if(byte[4] == '0') num_10 = 3, t4++;
    }

    if(num_10) {
        cout << "invalid" << endl;
        return 0;
    }

    cout << t1 << endl;
    cout << t2 << endl;
    cout << t3 << endl;
    cout << t4 << endl;

    return 0;
}
