#include <iostream>
using namespace std;

int main()
{
    int score;
    cin >> score;
    try
    {
        //start
        if (score > 100) throw 1;
        else if (score < 0) throw 2;
        //end
    }
    catch (int err)
    {
        cout << "Error(" << err << ")" << endl;
    }
    cout << "End of Program" << endl;
}
