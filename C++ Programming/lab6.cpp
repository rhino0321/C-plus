#include <iostream>
#include <iomanip>
#include <cmath>
const double PI=3.1415926;
double recperimeter(double Length,double Width);
double squareperimeter(double Length);
double circleperimeter(double radius);
int main()
{
    using namespace std;
    int type;
    do
    {
        cout << "===============" << endl;
        cout << "1.Rectangular 2.Square 3.Circle 4.Exit" << endl;
        cout << "Choose the type of perimeter you want to calculate:" << endl;
        cin >> type;
        switch (type)
        {
            double Length,Width,radius;
            case 1:
                cout << "Please enter the Length and Width respectively." << endl;
                cin >> Length >> Width;
                cout << fixed << setprecision(3) << "The perimeter of a rectangular with (Length,Width) =(" << Length << ", " << Width << ") is " << recperimeter(Length,Width) << endl;
                break;
            case 2:
                cout << "Please enter the Length." << endl;
                cin >> Length;
                cout << fixed << setprecision(3) << "The perimeter of a square with (Length) =(" << Length <<") is " << squareperimeter(Length) << endl;
                break;
            case 3:
                cout << "Please enter the radius of the circle." << endl;
                cin >> radius;
                cout << fixed << setprecision(3) << "The perimeter of a circle with (Radius) =(" << radius <<") is " << circleperimeter(radius) << endl;
                break;
            case 4:
                cout << "Goodbye!";
                break;
            default:
                cout << "Please follow the instruction carefully" << endl;
                break;
        }
    } while (type != 4);
    return 0;
}
double recperimeter(double Length,double Width)
{
    return (2 * (Length + Width));
}
double squareperimeter(double Length)
{
    return (4 * Length);
}
double circleperimeter(double radius)
{
    return (radius * 2 * PI);
}
/*double factorial(int n);
int main()
{
    using  namespace std;
    int n;
    cout << "Enter an integer value for the number of order n:" << endl;
    cin >> n;
    double S1=0,S2=0;
    for (int i=1; i<=n; i++)
    {
        S1 += (1 / static_cast<double>(i));
        S2 += (1 / factorial(i));
    }
    cout << "The result of S1 and S2 are:" << endl;
    cout << fixed << setprecision(5) << S1 <<endl;
    cout << fixed << setprecision(5) << S2 <<endl;
    return 0;
}
double factorial(int n)
{
    double ans;
    if (n == 1)
        ans = 1;
    else
        ans = n * factorial(n-1);
    return ans;
}*/
