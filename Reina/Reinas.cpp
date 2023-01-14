#include <iostream>
#include<stdio.h>
using namespace std;
int x=0;

//Aca comprobamos si la reina esta colocado en una posicion valida
//para que la posicion sea valida las reinas no deben en la misma columna
//y tampoco pueden estar en la misma fila, ni diagonal
bool validacion(int ArrayReinas[],int n, int k){
	int i;
	for(i=0;i<k;i++){
		if( (ArrayReinas[i]==ArrayReinas[k]) || (abs(k-i) == abs(ArrayReinas[k]-ArrayReinas[i]))){
			return false;
		}
	}
	return true;
}
	
void AsignarReinas(int ArrayReinas[],int n, int k){
	//este es el caso base que me indica que se ha encontrado una solucion
	//por lo cual ya no hay mas reinas por colocar.Hemos logrado poner
	//todas las reinas en el tablero deajerdrez
    int y=0, u=0;
    char *TableroReinas = new char[n];
	if(k==n){
		//print(reinas,n);
		x++;
		cout<<"Solucion "<<x<<" : ";
		for(int i=0;i<n;i++){
			cout<<ArrayReinas[i]<<" , ";
		}
         cout<<"\n";
           for(int k=0;k<(n*2)+1; k++){
            if(k%2==0){
                for(int f=0;f<(n*2)+1; f++){
                    if(f%2==0){
                        cout<<"+";
                    }
                    else{
                        cout<<"-"; 
                    }

                } 
                cout<<"\n";
            }
            else{
                    y=0;
                    for(int d=0; d<n;d++){
                        if(d==ArrayReinas[u]){
                            TableroReinas[d]='R';
                        }
                        else{
                            TableroReinas[d]=' ';
                        }
                    }
                    u=u+1;
                    for(int f=0;f<(n*2)+1; f++){
                    if(f%2==0){
                        cout<<"|";
                    }
                    else{
                        cout<<TableroReinas[y]; 
                        y=y+1;
                    }

                } 
                cout<<"\n";
            }      
         }

		cout<<endl;

	}
	//aun quedan reinas por colocar y el algoritmo debe seguir buscando
	else{
		for(ArrayReinas[k]=0;ArrayReinas[k]<n;ArrayReinas[k]++){
			if(validacion(ArrayReinas,n,k)){
				AsignarReinas(ArrayReinas,n,k+1);
			}
		}
	}
}
		
int main(int argc, char *argv[]) {
	int k=0;
	int j;
	cout<<"De que tamaño desea el tablero? : ";
	cin>>j;
    while (cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
            std::cin >> j;
        }
	int *ArrayReinas = new int[j];
   

	for(int i=0;i<j;i++){
		ArrayReinas[i]=-1;
	}

	AsignarReinas(ArrayReinas,j,k);

	return 0;
}