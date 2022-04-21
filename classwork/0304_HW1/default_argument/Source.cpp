#include <iostream>
using namespace std;
#define size 10

int maxHomeworkScore(int hw[], int num = 10);

int main()
{
    int homework[size];

    for (int i = 0; i < size; i++)
    {
        cin >> homework[i];
    }

    cout << maxHomeworkScore(homework, 8) << endl;
    cout << maxHomeworkScore(homework, 5) << endl;
    cout << maxHomeworkScore(homework) << endl;
}
//start
int maxHomeworkScore(int hw[], int num)
{
    int i, max;
    max = hw[0];
    for (int i = 1; i < num; i++)
    {
        if (max < hw[i])
            max = hw[i];
    }
    return max;
}
//end