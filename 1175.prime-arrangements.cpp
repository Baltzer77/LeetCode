/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

// @lc code=start
class Solution {
public:
    const int MOD=1e9+7;
    int countPrimes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;
        for(int p = 2; p * p <= n; p++) {
            if(!primes[p]) continue;

            for(int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }

        return count(primes.begin(), primes.end(), true);
    }

    long long fact(int n) {
        long long result = 1;
        for(long long i = 2; i <= n; i++) {
            result = (result * i ) % MOD;
        }

        return result;
    }
    int numPrimeArrangements(int n) {
        int primeCount = countPrimes(n);
        int nonPrime = n - primeCount;
        return (fact(primeCount) * fact(nonPrime)) % MOD;
    }
};
// @lc code=end

