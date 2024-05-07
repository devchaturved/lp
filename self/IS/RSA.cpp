#include <bits/stdc++.h>
using namespace std;
// x^y%p
int modpow(int x, int y, int p)
{
    int res = 1;
    x = x % p; // updated x
    while (y > 0)
    {
        if (y & 1){
        
            res = (res * x) % p;
        }
            y = y >> 1;

            x = (x * x) % p;
        
    }
    return res;
}

int computute_e(int phi)
{
    int e = 2;
    while (__gcd(e, phi) != 1)
    {
        e++;
    }
    return e;
}

int main()
{ 
    int p = 13;
    int q = 23;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = computute_e(phi);
    int d = 0;
    while (true)
    {
        if ((d * e) % phi == 1)
        {
            break;
        }
        d++;
    }

    int msg = 72;
    int c = modpow(msg, e, n);
    int decr = modpow(c, d, n);

    cout << " p= " << p << endl;
    cout << "q= " << q << endl;
    cout << " phi =" << phi << endl;
    cout << "encripting key :" << e << endl;
    cout << "decript key :" << d << endl;
    cout << " the cipher text is :" << c << endl;
    cout << "the plain text is :" << decr << endl;
}