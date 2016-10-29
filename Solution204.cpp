
//题目204，Count Primes 质数的个数

//埃拉托斯特尼筛法Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> res(n-1, true);
        res[0] = false;
        int count = 0, last = sqrt(n);
        for (int i=2; i<=last; i++) {
            if (res[i-1]) {
                for (int j=i*i; j<n; j+=i) {
                    res[j-1] = false;
                }
            }
        }
        for (int i=0; i<n-1; i++) {
            if (res[i]) {
                ++count;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n<2)
            return 0;
        vector<bool> res(n, false);
        int count = 1, last = sqrt(n);
        for (int i=3; i<n; i+2) {
            if (!res[i]) {
                count++;
                if (i>last)
                    continue;
                for (int j=i*i; j<n; j+=i)
                    res[j] = true;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        int count = n>>1, last = sqrt(n);
        bool *table = new bool[n];
        for (int i=3,j,step; i<=last; i+=2) {
            if (!table[i]) {
                for (step=i<<1, j=i*i; j<n; j+=step) {
                    if (!table[j]) {
                        table[j] = 1;
                        count--;
                    }
                }
            }
        }
        delete[] table;
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (--n < 2) return 0;
        int m = (n+1)/2, count = m, k, u = (sqrt(n) - 1)/2;
        bool notPrime[m] = [0];
        for (int i=1; i<=u; i++) {
            if (!notPrime[i]) {
                for (k = (i+1)*2*i; k<m; k+=i*2+1) {
                    if (!notPrime[k]) {
                        notPrime[k] = true;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};
