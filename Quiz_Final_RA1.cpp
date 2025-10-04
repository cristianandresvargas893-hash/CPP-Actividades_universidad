#include <iostream>
using namespace std;

int main()
{
    //Pregunta 1.1
    
    int n = 1 ,n1 = 2;
    float n2 = 1.5;
    char letra = 'a';
    
    cout<<n<<endl; //endl sirve para saltar una linea
    cout<<n1<<endl;
    cout<<n2<<endl;
    cout<<letra<<endl;
    
    /* PREGUNTA 1.2
    "Int sirve para valores de tipo entero y se puede usar por ejemplo para la edad"
    
    "float se usa para valores con decimal y se pueden usar por ejemplo para poner precios"
    
    "char se usa para guardar valores de un caracter y se usa por ejemplo en una lista de
    opciones"*/
    
    cout<<"\n\n";
    
    //Pregunta 2.1
    
    int a, b;
    cout<< "Ingrese el primer numero: ";cin>> a;
    cout<< "Ingrese el segundo numero: ";cin>> b;

    cout<< "Suma: "<< a + b << endl;
    cout<< "Resta: "<< a - b << endl;
    cout<< "Multiplicacion: "<< a * b << endl;
    if (b != 0) {
        cout<< "Division: " << a / b << endl;
        cout<< "Modulo: " << a % b << endl;
    } else {
        cout<< "No se puede dividir entre 0." << endl;
    }
    
    cout<<"\n\n";
    
    //Pregunta 2.2
    /* "==" verifica si un valor es igual a otro
    "!=" verica si un valor es diferente de otro
    
    EJEMPLO:
    */
    
    int numero = 10, numero1 = 20, num = 5,num1 = 5;

    if (num == num1) {
        cout << "num es igual a num1" << endl;
    } else if (numero != numero1) {
        cout << "numero es diferente de numero1" << endl;
    }
    cout<<"\n\n";
    //Pregunta 2.3:
    /* &&,||,! se puede usar para que los condicionales puedan trabajar con un rango de
    opciones o diferentes opciones dentro del mismo
    EJEMPLO: */ 
    
    int edad;
    cout<<"Ingresa tu edad: ";cin>>edad;

    if(edad >= 18 && edad <= 30) {
        cout<<"Eres un adulto"<<endl;
    }
    if(edad < 18 || edad > 60) {
        cout<<"Eres menor de edad o un adulto mayor (ya estas viejo)"<<endl;
    }
    if(!(edad < 18)) {
        cout<<"Mentiroso, no eres menor de edad"<<endl;
    }
    cout<<"\n\n";
    
    
    //Pregunta 3.1:
    
    int edad1;
    cout<<"Por favor ingrese su edad: ";cin>>edad;
    if(edad1 < 18){
        cout<<"Usted ya es mayor de edad"<<endl;
    } else {
        cout<<"Usted es menor de edad"<<endl;
    }
    cout<<"\n\n";
    
    //Pregunta 3.2
    /* "if", "else if", "else", quiere decir "Si...", "si no...", "De lo contrario..." y se usa principal mente para
    comparar valores,variables entre otros ejemplo: "Si "X" valor es igual/menor/mayor que
    "Y" valor entonces ocurre x cosa" */
    
    float nota;
    cout<<"Por favor Ingresa tu nota: ";cin>>nota;
    if (nota >= 4.0) {
        cout << "Excelente"<<endl;
    }else if (nota >= 3.0) {
        cout<<"Paso raspado mijo"<<endl;
    }else{
        cout<<"No paso, le falto nivel bro"<<endl;
    }
    
    cout<<"\n\n";
    
    
    //Pregunta 4.1:
    
    for(int i = 1; i <= 10; i++) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"\n\n";
    
    
    //Pregunta 4.2:
    
    int i = 10;
    while (i >= 1) {
        cout << i << " ";
        i--;
    }
    cout<<endl;
    cout<<"\n\n";
    
    
    //Pregunta 4.3
    
    int i1 = 2;
    do {
        cout<<i1<<" ";
        i1 += 2;
    }while(i1 <= 20);

    cout<<endl;
    cout<<"\n\n";
    
    
    //Pregunta 5.1
    
    int numeros[5];

    // Entrada
    for(int i2 = 0; i2 < 5; i2++) {
        cout<<"Ingresa el valor #" << i2 + 1 << ": ";cin>>numeros[i2]; //Ciclo para que el usuario ingrese todos los numeros
    }

    // Salida
    cout << "Los valores ingresados son: ";
    for (int i2 = 0; i2 < 5; i2++) {
        cout << numeros[i2] << " ";
    }
    cout << endl;
    cout<<"\n\n";
    
    
    //Pregunta 5.2
    /* Un array bidimensional es una tabla de filas y columnas y para acceder a sus
    elementos se necesita el indice de lo que quiere buscar "array filas[]columnas[]"*/
    
    
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    }; //Dos filas, tres columnas

    cout<<"Elemento en fila 1, columna 2: "<<matriz[0][1]<<endl; // Imprime 2
    cout<<"Elemento en fila 2, columna 3: "<<matriz[1][2]<<endl; // Imprime 6

    cout<<"\n\n";
    
    
    //Pregunta 5.3
    
    /*matriz 3x3 con los números del 1 al 9
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Y hasta ahi llegue porque no se como hacerlo :(
    */
    
    return 0;
}