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
 * Problem Name: Prime Path
 * Difficulty: 2.4 (Easy)
 * Categories: Math
 * Algorithms: Sieve of Eratosthenes, BFS
 */

vector<bool> sieve(int N) {
    vector<bool> is_prime(N, true);

    for(int i = 0; i < N; i += 2) is_prime[i] = false;
    is_prime[1] = false;
    is_prime[2] = true;

    for(int i = 3; i < sqrt(N); i += 2) {
        if(!is_prime[i]) continue;
        for(int j = i * i; j < N; j += 2 * i) is_prime[j] = false;
    }

    return is_prime;
}

int main() {
    init_cin();

    constexpr int N = 10000;
    vector<bool> is_prime = sieve(N);

    int C, S, T;
    cin >> C;

    while(C--) {
        cin >> S >> T;

        unordered_map<int, bool> vis;
        vis[S] = true;
        queue<int> q;
        int dist = 0;

        q.push(S);

        // BFS
        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                int current = q.front(); q.pop();
                if(current == T) goto found;

                // for each possible digit change (skip leading 0 and duplicates)
                for(int digit = 1; digit <= 1000; digit *= 10) {
                    for(int i = 0; i <= 9; i++) {
                        if((current / digit) % 10 == i || (digit == 1000 && i == 0)) continue;
                        int neigh = current - ((current / digit) % 10) * digit + i * digit;
                        if(is_prime[neigh] && !vis[neigh]) {
                            vis[neigh] = true;
                            q.push(neigh);
                        }
                    }
                }
            }

            dist++;
        }

        cout << "impossible" << endl;
        continue;

        found: cout << dist << endl;
    }

    return 0;
}
