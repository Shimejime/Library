int GetDigit(int Target) //桁数の取得
{
    int Result = 0;
    while(Target > 0)
    {
        Target /= 10;
        Result++;
    }
    return Result;
}
int GetFront(int Target) //先頭の文字を取得
{
    while(Target > 0)
    {
        if(Target < 10) return Target;
        Target /= 10;
    }
    return -1;
}

int GetBack(int Target) //末尾の文字を取得
{
    return Target % 10;
}

int GetReverse(int Target) //int型をReverseする
{
    int Result = 0;
    while(Target > 0)
    {
        Result *= 10;
        Result += (Target % 10);
        Target /= 10;
    }
    return Result;
}
