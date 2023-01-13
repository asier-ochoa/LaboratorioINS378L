//Escriba un programa C++, que dados dos arreglos ordenados los una en un nuevo arreglo también ordenado.
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include<iostream>
using namespace std;

/*void selectionSort(int arr[], int size)
{
   int min, temp;
   for (size_t i = 0; i < size - 1; i++)
   {
      min = i;
      for (size_t j = i + 1; j < size; j++)
      {
        if (arr[j] < arr[min])
        {
            min = j;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
      }
   }
}*/

void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (a[j] < a[min])
            min = j;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
   }
}

int main()
{
    bool valid = true;
    int lenOne, lenTwo;
    cout << "Ingresa la longitud del primer arreglo: ";
    do
    {
        cin>>lenOne;
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
    int arrOne[lenOne];
    for (int i = 0; i < lenOne; i++)
    {
        cout<<"Ingrese un valor: ";
        cin>>arrOne[i];
    }

    valid = true;
    cout << "Ingresa la longitud del segundo arreglo: ";
    do
    {
        cin>>lenTwo;
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
    int arrTwo[lenTwo];
    for (int i = 0; i < lenTwo; i++)
    {
        cout<<"Ingrese un valor: ";
        cin>>arrTwo[i];
    }

    int resultSize = lenOne + lenTwo;
    int arrResult[resultSize];

    for (size_t i = 0, k = lenOne; k < resultSize && i < lenTwo; i++, k++)
    {
        arrResult[i] = arrOne[i];
        arrResult[k] = arrTwo[i];
    }

    selectionSort(arrResult, resultSize);

    for (size_t i = 0; i < resultSize; i++)
    {
        cout<< arrResult[i] << ' ';
    }
    return 0;
}