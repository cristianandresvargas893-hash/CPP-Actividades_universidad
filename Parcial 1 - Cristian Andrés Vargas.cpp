#include <iostream>
#include <string>
using namespace std;

    //Parcial 1
    
    //Sección A
    
    /*Pregunta 1: ¿cuál declara y define una variable entera con valor 10? 
    Respuesta: Opción B "int x = 10"
    
    
    Pregunta 2: ¿Qué imprime?   std::cout << 7/2 << " " << 7/2.0;
    Respuesta: opción B "3 y 3.5"
    
    
    Pregunta 3: Con bool a=true, b=false; ¿Qué imprime?
    std::cout << (a&&b) << " " << (a||b) << " " << (!b);
    Respuesta: Respuesta: opción B "0 1 1"
    
    
    Pregunta 4: Dado int x=3; if (x=0) { ... } else { ... } ¿qué ocurre? 
    Respuesta: Opción C "Entra al else porque el valor es 0 tras la asignación"
    
    
    Pregunta 5: do-while respecto a while
    Respuesta: Opción B "Ejecuta al menos una vez"
    
    
    Pregunta 6: ¿Cuál lee dos enteros separados por espacio?
    Respuesta: Opción C "cin>>a>>b;"
    
    
    Pregunta 7: ¿Qué imprime? int a=5, b=2; std::cout << a + b*3 << '\n';
    Respuesta: Opción A "11"
    
    
    Pregunta 8: ¿Cuál firma pasa un entero por referencia?
    Respuesta: Opción  B "void f(int& n)"
    
    
    Pregunta 9: ¿Qué hace continue en un for?
    Respuesta: Opción B "Salta a la siguuiente iteración"
    
    
    Pregunta 10: ¿Cuál condición es verdadera?
    Respuesta: Opción A "(3 == 3) && !(2 > 5)"
    
    
    SECCIÓN B
    (Las respuestas pueden variar dependiendo de el compilador)

Pregunta 1:
int a=5, b=2; 
std::cout << a + b*3 << std::endl;

Respuesta:
11

Pregunta 2:
int n=0; 
while (n<3) { 
std::cout << n << " "; 
n++;

Respuesta:
0 1 2 
Pregunta 3:
int x=10; 
if (x%2==0) std::cout << "par"; 
else        
std::cout << "impar";

Respuesta:
par
Pregunta 4:
int i=3; 
do { 
    std::cout << i--; 
} while (i>0); 

Respuesta:
321
Pregunta 5:
int a=1; 
int b = (a++ > 1) ? 100 : 200; 
std::cout << a << " " << b;

Respuesta:
2 200

SECCIÓN C:
Respuesta 1:*/

//mayor de tres con if/else
int max3(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}


//Respuesta 2:
//suma
int sumaRango(int a, int b) {
    int suma = 0;
    for (int i = a; i <= b; ++i) suma += i;
    return suma;
}

//Respuesta 3:
//Encontrar digito
bool contieneDigito(int n, int d) {
    if (n == 0 && d == 0) return true;
    while (n > 0) {
        int dig = n % 10;
        if (dig == d) return true;
        n /= 10;
    }
    return false;
}



//Respuesta 4:
//tabla de multiplicar
void tablaMultiplicar(int n) {
    for (int i = 1; i <= 10; ++i) {
        cout << n << " x " << i << " = " << (n * i) << endl;
    }
}







int main()
{
    // Pruebas de que funciona bien:
    cout<<"max3(5,9,3) = "<<max3(5,9,3)<<endl;  // da 9
    cout<<"sumaRango(3,6) = "<<sumaRango(3,6)<<endl;  // da 18
    cout<<"contieneDigito(0,0) = "<<(contieneDigito(0,0)?"true":"false")<<endl; // true
    cout<<endl<<"Tabla del 5:" << endl;tablaMultiplicar(5);

    return 0;
}