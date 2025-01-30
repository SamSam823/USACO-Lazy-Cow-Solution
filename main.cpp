#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

vector<int> powers_of_3;

void precompute_powers() {
    int val = 1;
    while (val <= 1e12) {
        powers_of_3.push_back(val);
        if (val > (1e12 / 3)) break; 
        val *= 3;
    }
    reverse(powers_of_3.begin(), powers_of_3.end()); 
}

int min_energy_to_satisfy(int m, int b) {
    int energy = 0, cases_done = 0;
    
    for (int p : powers_of_3) {
        while (m > 0 && cases_done < b) {
            int max_cases = b - cases_done;
            int use = min(max_cases / p, m); 
            if (use == 0) break; 
            
            cases_done += use * p;
            energy = (energy + use * (p * 3 % MOD)) % MOD;
            m -= use;
        }
        if (cases_done >= b) break;
    }
    return energy;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute_powers();
    
    int D;
    cin >> D;
    vector<int> results(D);
    
    for (int i = 0; i < D; i++) {
        int m, b;
        cin >> m >> b;
        results[i] = min_energy_to_satisfy(m, b);
    }
    
    for (int res : results) {
        cout << res << '\n';
    }
    
    return 0;
}
