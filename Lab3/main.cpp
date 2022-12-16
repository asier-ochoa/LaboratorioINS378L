//Yeuris Terrero 1099399
//14/10/2022

#include<string>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    float r, d, a, c, x, y;

    cout<<"Ingrese el radio: ";
    cin>>r;
    d = 2*r;

    vector<vector<char>> drawPlano( r * 4, vector<char>(r*4,' '));
    
    
    for (float t = 0.0; t < d; t+=0.1)
    {
        y = r * cos(t) + r + 1;
        x = 0.5 * r * sin(t) + r + 1;
        drawPlano[x][y] = '*';
    }
    


    for (const auto& row : drawPlano)
    {
        string line;
        for (auto cell : row)
        {
            line += cell;
        }
        cout << line << endl;
        
    }

    return 0;
}