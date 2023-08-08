#include <iostream>
#include <cstring>
using namespace std;

void print(int x_start, int y_start, char side, int &flag);

int main()
{
    char direc[50], side, next;
    int x, y, x_start, y_start, idx = 0, flag = 1;
    cin >> x >> y;
    cin >> x_start >> y_start >> side;
    cin.get(next);
    cin.getline(direc, 50);
    while (direc[idx] != '\0')
    {
        switch(direc[idx])
        {
            case 'F':
                if (side == 'E') {x_start++; break;}
                else if (side == 'S') {y_start--; break;}
                else if (side == 'W') {x_start--; break;}
                else {y_start++; break;}

            case 'R':
                if (side == 'E') {side = 'S'; break;}
                else if (side == 'S') {side = 'W'; break;}
                else if (side == 'W') {side = 'N'; break;}
                else {side = 'E'; break;}

            case 'L':
                if (side == 'E') {side = 'N'; break;}
                else if (side == 'S') {side = 'E'; break;}
                else if (side == 'W') {side = 'S'; break;}
                else {side = 'W'; break;}
        }
        idx++;
        if (x_start > x) {x_start--; print(x_start, y_start, side, flag); break;}
        else if (x_start < 0) {x_start++; print(x_start, y_start, side, flag); break;}
        else if (y_start < 0) {y_start++; print(x_start, y_start, side, flag); break;}
        else if (y_start > y) {y_start--; print(x_start, y_start, side, flag); break;}
    }
    if (flag)
    {
        cout << x_start << " " << y_start << " " << side;
    }

}
void print(int x_start, int y_start, char side, int &flag)
{
    cout << x_start << " " << y_start << " " << side << " ";
    cout << "LOST";
    flag = 0;
}
