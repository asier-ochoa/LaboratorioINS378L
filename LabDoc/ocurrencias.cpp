//Escriba un programa C++, que dado un arreglo con múltiples valores, imprima la 
//ocurrencia de cada elemento en el mismo.
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int length;
    bool valid = true;
    cout<<"Digite la longitud del arreglo: ";
    do
    {
        cin>>length;
        if (cin.good())
        {
            valid = false;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores all content from input until the new line starts
            cout << "Tipo de dato incorrecto, digitelo de nuevo: ";
        }
    } while (valid);
    
    int array[length];

    for (size_t i = 0; i < length; i++)
    {
        cout<<"Ingrese un valor: ";
        cin>>array[i];
    }

    int seen[length];
    for (size_t i = 0; i < length; i++)
    {
        seen[i] = 0;
    }
    

    for (size_t i = 0; i < length; i++)
    {
        if (seen[i] == 0)
        {
            int ocurrence = 0;
            for (size_t j = i; i < length; j++)
            {
                if (array[j] == array[i])
                {
                    ocurrence += 1;
                }
            }
            seen[i] = ocurrence;
        }
    }
    
    for (size_t i = 0; i < length; i++)
    {
        cout << array[i] << " ocurre " << seen[i] << " " << " veces" << endl;
    }
    return 0;
}