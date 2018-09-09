int reverse(int num)
{
    long res = 0;
    while(num != 0)
    {
        res =  res * 10 + num % 10;

        num /= 10;
    }
    return fabs(res) > numeric_limits<int>::max() ? 0 : res;

}
