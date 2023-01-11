//Escriba un programa C++, que dado un arreglo con múltiples valores, imprima la 
//ocurrencia de cada elemento en el mismo.


#include<iostream>
using namespace std;
main()
{
    int a[10], i,j,v, count, n[10], m, c = 0;

    cout<<"Digite los valores del arreglo\n";
    for(i=0;i<=9;i++)
    {
        cout<<"Digite el valor numero " <<i+1<<" : ";
        cin>>a[i];
    }

    for(j=0;j<=9;j++)
    {
        v=a[j];
        count=0;
        m=1;
        for (i=0;i<=9;i++)
        {
           if (v==a[i])
          count++;
            
        }

        for (i=0;i<c;i++)
        {
            if (n[i]==v)
             m=0;    
             
        }
        if (m==1)
        {
        cout<<"El valor "<<v<<" se repite "<<count<<" veces\n";
        n[c]=v;
        c++;
        }
        
        
        


    }

}