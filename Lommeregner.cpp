#include <iostream>
#include <string>

using namespace std;

float top;
float bottom; 
float result;
int operation;


int main()
{
    cout << "Give top number";
    cin >> top;
    cout << "Give bottom number";
    cin >> bottom;
    cout << "Choose operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide";
    cin >> operation;
    if ((operation == 4) && (bottom == 0.0))
        {
            cout << "Cannot divide by zero!";
            return 0;
        }
    switch (operation)
    {
    case 1:
        result = top + bottom;
        break;
    case 2:
        result = top - bottom;
        break;
    case 3: 
        result = top * bottom;
        break;
    case 4:
        result = top / bottom;
        break;
    default:
        break;
    }
    cout << "Result: " << result;
}
