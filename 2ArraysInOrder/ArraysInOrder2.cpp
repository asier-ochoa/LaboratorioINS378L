// ArrayOrder.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int validacion(int n, int i, int num) {
	std::cout << "Inserte el numero positivo " << i + 1 << " del primer arreglo porfavor ( " << i + 1 << "/" << n << " ):\n";
	std::cin >> num;
		while (std::cin.fail() || num <0)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "No ha ingresado un numero positivo, favor ingresar un solo caracter o un numero positivo por espacio en el arreglo \n";
			std::cin >> num;
		}	
		return num;
}

int main()
{
	float mayormomentaneo, menor = 0;
	bool boolCondicion = true;
	int i = 0, n = 0, w, arraySize, posicionmenor, x = 0, c = 0, l = 1, num=0;
	//Arreglo 1
	//Resizesing dinamicamente

	cout << "¿Cuantos elementos desea posea del arrego" << l << "?:" << "\n";
	cin >> n;
	while(cin.fail() || n<=0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		std::cout << "No ha ingresado un numero valido, porfavor inserte un numero de 1 hasta infinito positivo: " << endl;
		cin >> n;
	}

	int* array1 = new int(n);
	//Capturando
	i = 0;
	while (i < n) {
		array1[i] = validacion(n,i,num);
		i = i + 1;
	}

	//Sort
	for (int y = 0; y < n - 1; y++) {
		// buscando el valor menor
		menor = array1[y];
		posicionmenor = y;
		for (int x = y; x < n - 1; x++) {
			if (menor > array1[x + 1]) {
				menor = array1[x + 1];
				posicionmenor = x + 1;

			}
			else {
				menor = array1[posicionmenor];
			}
		}
		//Asignar valor menor
		array1[posicionmenor] = array1[y];
		array1[y] = menor;

	}

	// Imprimiendo
	std::cout << "Arreglo " << l << " esta compuesto por :\n";
	for (x = 0; x < n; x++) {
		std::cout << array1[x] << " ";
	}
	std::cout << "\n";

	l = 2;
	//Arreglo 2
	//Resizesing dinamicamente
	std::cout << "¿Cuantos elementos desea posea del arrego" << l << "?:" << "\n";
	cin >> w;
	while (cin.fail() || w <= 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		std::cout << "No ha ingresado un numero valido, porfavor inserte un numero de 0 hasta infinito positivo: " << endl;
		cin >> w;
	}
	int* array2 = new int(w);
	//Capturando
	i = 0;
	while (i < w) {
		array2[i] = validacion(w, i, num);
		i = i + 1;
	}

	//Sort
	
	for (int y = 0; y < w - 1; y++) {
		// buscando el valor menor
		menor = array2[y];
		posicionmenor = y;
		for (int x = y; x < w - 1; x++) {
			if (menor > array2[x + 1]) {
				menor = array2[x + 1];
				posicionmenor = x + 1;

			}
			else {
				menor = array2[posicionmenor];
			}
		}
		//Asignar valor menor
		array2[posicionmenor] = array2[y];
		array2[y] = menor;

	}

	// Imprimiendo
	std::cout << "Arreglo " << l << " esta compuesto por :\n";
	for (x = 0; x < w; x++) {
		std::cout << array2[x] << " ";
	}
	std::cout << "\n";

	// Uniendo los dos arrays en un unuevo arreglo
	int* array3 = new int (n + w);
	for (int i = 0; i < n; i++) {
		array3[i] = array1[i];
	}
	for (int i = 0; i < w; i++) {
		array3[i + (int)n] = array2[i];
	}
	//Sort
	for (int y = 0; y < n + w - 1; y++) {
		// buscando el valor menor
		menor = array3[y];
		posicionmenor = y;
		for (int x = y; x < n + w - 1; x++) {
			if (menor > array3[x + 1]) {
				menor = array3[x + 1];
				posicionmenor = x + 1;

			}
			else {
				menor = array3[posicionmenor];
			}
		}
		//Asignar valor menor
		array3[posicionmenor] = array3[y];
		array3[y] = menor;

	}

	// Imprimiendo
	std::cout << "El arreglo ordenado producto de la union de los anteriores es :\n";
	for (x = 0; x < n + w; x++) {
		std::cout << array3[x] << " ";
	}
	std::cout << "\n";
}

	






// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
