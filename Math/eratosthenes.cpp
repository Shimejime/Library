#include <iostream>
#include <vector>

using namespace std;
using Int = int64_t;

vector<Int> eratosthenes(const Int &N)
{
    vector<Int> is_prime(N + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for(Int j = 4; j <= N; j += 2) is_prime[j] = 0;
    for(Int i = 3; i * i <= N; i += 2)
    {
        if(is_prime[i] == 0) continue;
        for(Int j = 2 * i; j <= N; j += i)
        {
            is_prime[j] = 0;
        }
    }
    return is_prime;
}