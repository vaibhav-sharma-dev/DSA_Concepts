// Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is V₁. A day is record breaking if it satisfies both of the following conditions:

// The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.

// Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.

// Note that the very first day could be a record breaking day!

// Please help Isyana find out the number of record breaking days.

#include <iostream>
using namespace std;

/*int max(int arr[], int size)
{
    int max_day = arr[0];
    for (int i=1; i<=size; i++)
    {
        if (arr[i]>max_day)
            max_day = arr[i];
    }
    return max_day;
}*/

int main()
{
    int test;
    cin >> test;
    for (int i=1; i<=test; i++)
    {
        int days;
        cin >> days;
        
        int arr[days];
        for (int i=0; i<days; i++)
            cin >> arr[i];

        int record_brk = 0, day = 0, max = arr[day];

        if (arr[day] > arr[day+1])
            record_brk++;

        for (day=1; day<days-1; day++)
        {
            if (arr[day]>max && arr[day]>arr[day+1])
            {
                record_brk++;
                max = arr[day];
            }
        }

        if (arr[days-1] > max)
            record_brk++;

        for (int i=1; i<=test; i++)
            cout << "#" << test << ":" << record_brk;
    }
}