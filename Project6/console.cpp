#include <iostream>
#include "logika.h"

using namespace std;

int main()
{
    float x, y, S, R, C;  

    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    try {
        Calculate(x, y, S, R, C);

   
        cout << "S = " << S << endl;
        cout << "R = " << R << endl;
        cout << "C = " << C << endl;
    }
    catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    system("pause");
    return 0;
}