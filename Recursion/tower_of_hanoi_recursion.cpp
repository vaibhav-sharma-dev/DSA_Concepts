#include <iostream>
using namespace std;

void tower_of_hanoi(int disks, char src, char dest, char help)
{
    if (disks==0)
        return;

    tower_of_hanoi(disks-1, src, help, dest);

    cout << "Move from " << src << " to " << dest << endl;

    tower_of_hanoi(disks-1, help, dest, src);
}

int main()
{
    int disks;
    cin >> disks;

    char src = 'A';
    char dest = 'B';
    char help = 'C';
    tower_of_hanoi(disks, src, dest, help);
}