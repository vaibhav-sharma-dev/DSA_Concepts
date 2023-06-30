#include<iostream>
using namespace std;

// How many numbers between 1 and 1000 are divisible by 5 or 7 ?

int main()
{
    int n, a, b;
    cin >> n;
    cin >> a >> b;

    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    cout << c1+c2-c3;
}


