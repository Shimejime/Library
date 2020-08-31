#include <iostream>
#include <vector>
#include <map>

using namespace std;
using Int = int64_t;

// O(√n)
map<Int, Int> prime_factor(Int N)
{
    map<Int, Int> result;
    for(Int i = 2; i * i <= N; i++)
    {
        while(N % i == 0)
        {
            result[i]++;
            N /= i;
        }
    }
    if(N != 1) result[N] = 1;
    return result;
}


// エラストテネスの篩を用いた高速素因数分解:O(nlogn)
// is_prime[x] := 最小の素因数を保持する
vector<Int> eratosthenes(const Int &N);
map<Int, Int> prime_factor(Int N, const vector<Int> &is_prime)
{
    map<Int, Int> result;
    while(N > 1)
    {
        result[is_prime[N]]++;
        N = N / is_prime[N];
    }
    return result;
}

vector<Int> eratosthenes(const Int &N)
{
    vector<Int> is_prime(N + 1);
    for(int i = 0; i < is_prime.size(); i++) is_prime[i] = i;
    is_prime[1] = 0;

    for(Int i = 2; i * i <= N; i++)
    {
        if(is_prime[i] != i) continue;
        for(Int j = 2 * i; j <= N; j += i)
        {
            is_prime[j] = min(is_prime[j], i);
        }
    }
    return is_prime;
}
