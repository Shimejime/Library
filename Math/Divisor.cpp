template<typename type>
vector<type> divisor(type n)
{
    vector<type> res;
    for(type i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
