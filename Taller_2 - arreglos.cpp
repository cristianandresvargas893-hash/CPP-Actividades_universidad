#include <iostream>
#include <algorithm>
using namespace std;


// tablero del tres en raya
void mostrarTablero(char tablero[3][3]) {
        for(int i6 = 0; i6 < 3; i6++) {
            cout<< " ";
            for(int j6 = 0; j6 < 3; j6++) {
                cout << tablero[i6][j6];
                if(j6 < 2) cout<< " | ";
            }
            cout <<endl;
            if(i6<2)cout<<"---+---+---\n";
        }
    }
    
int main()
{
    // Taller 2 - Arrays
    
    // Ejercicio 1 - mediana
    
    //Creamos las variables
    int n;
    cout<< "Ingrese el tamaño del array: ";cin>>n;
    
    int arr[n];
    cout<<"Ingrese los elementos de su array: \n";
    for (int i = 0; i<n; i++)cin>>arr[i];
    
    //Ordenemos el array
    sort(arr, arr+n);
    
    double mediana;
    if (n % 2 == 0) {
        //Promedio de los valores del centro
        mediana = (arr[n/2-1] + arr[n/2]) / 2.0;} else {
            mediana = arr[n/2];
        }
        
        //Mostramos los resultados
        cout<< "La mediana es: " <<mediana <<endl;
    cout << "\n\n";
    
    
    //Ejercicio 2 - busqueda binaria
    
    int n1, x;
    cout<< "Ingrese el tamaño del array: ";cin>>n1;
    int arr1[n1];
    cout<<"Ingrese los elementos de su array: \n";
    for (int i1 = 0; i1<n1; i1++)cin>>arr1[i1];
    
    sort(arr1, arr1 + n1); //orden del array
    
    cout<<"Ingrese el numero que desea buscar: "; cin>>x;
    
    int inicio = 0, fin = n1-1, mid;
    bool encontrado = false;
    
    while (inicio <= fin) {
        mid = (inicio + fin) / 2;
        if(arr1[mid] == x) {
            encontrado = true;
            break;
        } else if(arr1[mid] < x) {
            inicio = mid + 1;
        } else {
            fin = mid - 1;
        }
    }
    
    if (encontrado)
    cout<<"El número: " <<x<<" Se encontró en la posición: " << mid << endl;
    else
    cout<<"El número no esta en el array\n";
    
    cout<<"\n\n";
    
    
    //Ejercicio 3 - Transpuesta
    
    int filas, columnas;
    cout<<"Ingrese filas y columnas: ";cin>>filas>>columnas;
    int matriz[filas][columnas];
    cout<<"Ingrese los elementos de su matríz: \n";
    for(int i2 = 0; i2 < filas; i2++) {
        for (int j = 0; j < columnas; j++)
{           
            cin>>matriz[i2][j];
        }
    }
    cout<<"matríz Transpuesta: \n";
    for (int j = 0; j < columnas; j++) {
        for(int i2 = 0; i2 < filas; i2++) {
            cout <<matriz[i2][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
    
    //Ejercicio 4 - Inventario
    
    const int n3 = 3;
    string productos[n3];
    int cantidades[n3];
    cout<<"Ingrese productos y sus cantidades: \n";
    for(int i3 = 0; i3< n3; i3++) {
        cout<<"Producto " << i3+1<< ": ";cin>>productos[i3];
        cout<<"Cantidad ";cin >>cantidades[i3];
    }
    cout<< "\n===== Inventario =====\n";
    for(int i3 = 0; i3 < n3; i3++) {
        cout << productos[i3] << " -> " << cantidades[i3] << endl;
    }
    cout<<"\n\n";
    
    
    //Ejercicio 5 - selección
    
    int n4;
    cout<<"Ingrese el tamaño del array: ";cin>>n4;
    int arr4[n4];
    cout<<"Ingrese los elementos del array: \n";
    for(int i4 = 0; i4 < n4; i4++)cin>>arr4[i4];
    
    for (int i4 = 0; i4 < n4-1; i4++) {
        int minIndex = i4;
        for(int j4 = i4+1; j4 < n4; j4++) {
            if(arr4[j4] < arr4[minIndex]) {
            minIndex = j4;
        }
    }
    swap(arr4[i4], arr[minIndex]);
    }

    cout<< "Array ordenado: ";
    for(int i4 = 0; i4 < n4; i4++) cout<< arr[i4]<<" ";
    cout<< endl;
    
    cout<<"\n\n";
    
    
    //Ejercicio 6 - Elementos duplicados
    int n5;
    cout<<"Ingrese el tamaño de del array: ";cin>> n5;
    int arr5[n5];
    cout<<"Ingrese los elementos: \n";
    for(int i5 = 0; i5 < n5; i5++)cin>>arr5[i5];
    
    cout<<"duplicados: ";
    for(    int i5=0;i5<n5;i5++) {
        for(int j5= i5 + 1; j5<n5; j5++) {
            if(arr5[i5] == arr5[j5]) {
                cout<<arr5[i5]<<" ";
                break;
            }
        }
    }
    cout<<endl;
    cout<<"\n\n";
    
    
    //Ejercicio 7 - Triki (tres en raya)

    char tablero[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'} };
    char jugador = 'x';
    int jugada,fila,col;
    
    for(int turnos = 0; turnos < 9; turnos++){
        mostrarTablero(tablero);
        cout<<"jugador "<<jugador<<"Elija una posición: ";cin>>jugada;
        
        fila = (jugada - 1)/3;
        col = (jugada - 1)%3;
        
        if(tablero[fila][col] != 'x' && tablero[fila][col] != 'O') {
            tablero[fila][col] = jugador;
            //Cambia el jugador
            jugador = (jugador == 'x') ? '0':'x';
        } else {
            cout<<"Casilla ocupada, intente otra.\n";
            turnos--;
        }
    }
    mostrarTablero(tablero);
    cout<<"Juego terminado (sin verificación de gnador aún).\n";
    
    //Muy dificil demasiados errores y muy dificil hacer que todo funcione correctamente.
}