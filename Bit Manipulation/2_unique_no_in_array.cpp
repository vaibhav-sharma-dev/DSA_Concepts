#include <iostream>
using namespace std;

// Write a program to find 2 unique numbers in an array where all numbers except two, are present twice

// 2, 4, 6, 7, 4, 5, 6, 2

int main()
{
    int size;
    cin >> size;

    int arr[size];

    int xor_arr = 0;
    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
        xor_arr = xor_arr^arr[i];
    }

    int temp = xor_arr;
    int set_bit = 0;
    int pos = 0;

    while (set_bit!=1)
    {
        set_bit = xor_arr & 1;
        pos++;
        xor_arr = (xor_arr>>1);
    }

    // xor_arr = (xor_arr<<pos);
    pos--;
    int xor_pos = 0;

    for (int i=0; i<size; i++)
    {
        if (arr[i] & (1<<pos))
            xor_pos = arr[i]^xor_pos;
    }

    cout << xor_pos << "\n" << (xor_pos^temp);

    
}