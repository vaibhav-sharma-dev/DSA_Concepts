#include <iostream>
using namespace std;

// character array
// d ord ie

int main()
{
    int size;
    cin >> size;
    cin.ignore();

    char arr[size+1];
    cin.getline(arr, size);
    cin.ignore();

    int sum = 0;
    int max_length = 0;
    int max_word = 0;
    int max_index = 0;

    for (int i=0; i<size+1; i++)
    {
        if (arr[i]==' ' || arr[i]=='\0')
        {
            if (sum>max_length)
            {
                max_length = sum;
                max_word = max_index;
            }

            max_index = i+1;
            sum = -1;
        }
        
        sum++;
    }    

    cout << max_length << endl;

    for (int i=0; i<max_length; i++)
        cout << arr[i+max_word];
}