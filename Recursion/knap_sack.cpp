#include <iostream>
using namespace std;

int knap_sack(int value[], int weight[], int n, int W)
{
    if (n==0 || W==0)
        return 0;

    if (weight[n-1]>W)
        return knap_sack(value, weight, n-1, W);
    
    return max(knap_sack(value, weight, n-1, W-weight[n-1])+value[n-1], knap_sack(value, weight, n-1, W));

}

int main()
{
    int W;
    cin >> W;

    int no_of_items;
    cin >> no_of_items;

    int value[no_of_items], weight[no_of_items];

    for (int i=0; i<no_of_items; i++)
    {
        cin >> value[i];
        cin >> weight[i];
    }
    cout << knap_sack(value, weight, no_of_items, W);
}