int Mergesort(int *v, int left, int right)
{
    if(right - left <= 1) return 0;
    int res = 0, n = right - left - 1;
    int mid = (left + right) / 2;
    res += Mergesort(v, left, mid);
    res += Mergesort(v, mid, right);
    int buf[n];
    int idx = 0;
    for(int i = left; i < mid; i++) { buf[idx] = v[i], idx++; }
    for(int i = right - 1; i >= mid; i--) { buf[idx] = v[i], idx++; }
    int posL = 0, posR = n;
    for(int i = left; i < right; i++)
    {
        if(buf[posL] <= buf[posR]) { v[i] = buf[posL++]; }
        else { v[i] = buf[posR--]; }
    }
    return res + right - left;
} 