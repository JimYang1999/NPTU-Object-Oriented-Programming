#include <iostream>
using namespace std;
#define size 10
//start
double avgHomeworkScore(int hw[], int num = 10)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (hw[j] < hw[j + 1])
            {
                int temp = hw[j];
                hw[j] = hw[j + 1];
                hw[j + 1] = temp;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += hw[i];
    }

    return sum / (double)num;
}
//end
int main()
{
    int homework[size];

    for (int i = 0; i < size; i++)
    {
        cin >> homework[i];
    }

    cout << avgHomeworkScore(homework, 3) << endl;
    cout << avgHomeworkScore(homework, 5) << endl;
    cout << avgHomeworkScore(homework) << endl;
}



