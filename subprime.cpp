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
 * Problem Name: Subprime
 * Difficulty: 4.1 (Medium)
 * Categories: 
 * Algorithms: Sieve of Eratosthenes
 */

vi sieve(int LIM) {
    vector<bool> is_prime(LIM, true);
    vector<int> primes = {2};

    for(int i = 4; i < LIM; i += 2) is_prime[i] = false;
    is_prime[1] = is_prime[0] = false;

    for(int i = 3; i < sqrt(LIM); i += 2) {
        if(!is_prime[i]) continue;
        primes.push_back(i);
        for(int j = i * i; j < LIM; j += 2 * i) is_prime[j] = false;
    }

    for(int i = sqrt(LIM); i < LIM; i++) if(is_prime[i]) primes.push_back(i);

   return primes;
}

// returns true if a is a substring of b
bool is_ss(string& a, string b) {
    return b.find(a) != string::npos;
}

int main() {
    init_cin();

    vi pr = sieve(1.5e6); // contains at least 1e5 primes

    int L, H;
    string S;

    cin >> L >> H >> S;

    int result = 0;

    rep(i, L - 1, H) if(to_string(pr[i]).find(S) != string::npos) result++;

    cout << result << endl;

    return 0;
}
