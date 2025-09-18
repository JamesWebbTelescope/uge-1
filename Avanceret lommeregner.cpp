#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

double top;
double bottom; 
double result;
int operation;
bool validate;

void validateInput()
{
    validate = cin.fail();
    if(validate == true)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number\n";
    }
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if ((b == 0.0))
        {
            cout << "Cannot divide by zero!";
            return 0;
        }
    return a / b;
}

double squareroot(double a)
{
    return sqrt(a);
}

double power(double a, double b)
{
    return pow(a, b);
}

int main()
{
    cout << "Give top number";
    cin >> top;
    validateInput();
    cout << "Give bottom number";
    cin >> bottom;
    validateInput();
    cout << "Choose operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n 5. Square root\n 6. Power";
    cin >> operation;
    switch (operation)
    {
    case 1:
        result = add(top, bottom);
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
