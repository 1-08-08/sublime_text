/*
                                BINARY SEARCH
                            Time Complexity : O(nlogn)
*/

int Binary_Search(int n, int x)
{
    int l = 0, r = n, mid;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        if (v[mid - 1] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return (v[l] == x);
}

double exp(double a, int b)
{
    double res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

double Binary_Search_Real_Number(int n, int x)
{
    double l = 0, r = 1000000000, mid, e = 0.000001;
    while ((r - l) >= e)
    {
        mid = (l + r) / 2;
        if (exp(mid, x) > n)
            r = mid;
        else
            l = mid;
    }
    return l;
}