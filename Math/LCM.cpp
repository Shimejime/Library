template<typename T> T GCD(T a, T b)
{
    if(b == 0) return a;
    return GCD(b, a % b);
}
template<typename T> T LCM(T a, T b)
{
    T g = GCD(a, b);
    return a / g * b;
}
