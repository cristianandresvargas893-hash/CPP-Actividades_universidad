#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

// ====== EJERCICIO 1 ======
// Calcula el número mínimo, máximo y promedio
void ejercicio1() {
    int n;
    cout << "Cuantos numeros deseas ingresar? ";
    cin >> n;

    int num, min, max, suma = 0;
    cout << "Ingresa los numeros:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (i == 0) min = max = num; // el primero define min y max
        if (num < min) min = num;
        if (num > max) max = num;
        suma += num;
    }
    float prom = (float)suma / n;
    cout << "Minimo: " << min << "\nMaximo: " << max << "\nPromedio: " << prom << endl;
}

// ====== EJERCICIO 2 ======
// Rota los números de un arreglo hacia la derecha varias posiciones
void ejercicio2() {
    int n;
    cout << "Cuantos numeros deseas ingresar? ";
    cin >> n;

    int v[50];
    cout << "Ingresa los numeros:\n";
    for (int i = 0; i < n; i++) cin >> v[i];

    int rot; //rot = k = posiciones a rotar
    cout << "Cuantas posiciones deseas rotar a la derecha? ";
    cin >> rot;

    // Aseguramos que rot no sea mayor que n
    rot = rot % n;

    // Rotación circular
    for (int r = 0; r < rot; r++) {
        int ultimo = v[n - 1];
        for (int i = n - 1; i > 0; i--) {
            v[i] = v[i - 1];
        }
        v[0] = ultimo;
    }

    cout << "Arreglo rotado:\n";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

// ====== EJERCICIO 3 ======
// Elimina espacios repetidos en una frase
void ejercicio3() {
    string frase;
    cout << "Ingresa una frase: ";
    cin.ignore();                    // limpiamos el buffer
    getline(cin, frase);
    string resultado = "";
    bool espacio = false;
    for (char c : frase) {
        if (c == ' ') {
            if (!espacio) resultado += c; // deja solo un espacio
            espacio = true;
        } else {
            resultado += c;
            espacio = false;
        }
    }
    cout << "Frase normalizada/corregida sin espacios: " << resultado << endl;
}

// ====== EJERCICIO 4 ======
// Calcula y muestra la suma de cada fila y cada columna de una matriz
void ejercicio4() {
    int f, c;
    cout << "Filas: "; cin >> f;
    cout << "Columnas: "; cin >> c;

    int m[10][10]; // matriz de máximo 10x10
    cout << "Ingresa los valores:\n";
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    // ---- Suma por filas ----
    cout << "\nSuma por filas:\n";
    for (int i = 0; i < f; i++) {
        int sumaFila = 0;
        for (int j = 0; j < c; j++) {
            sumaFila += m[i][j];
        }
        cout << "Fila " << i + 1 << ": " << sumaFila << endl;
    }

    // ---- Suma por columnas ----
    cout << "\nSuma por columnas:\n";
    for (int j = 0; j < c; j++) {
        int sumaCol = 0;
        for (int i = 0; i < f; i++) {
            sumaCol += m[i][j];
        }
        cout << "Columna " << j + 1 << ": " << sumaCol << endl;
    }
}

// ====== EJERCICIO 5 ======
// Guarda estudiantes, muestra el top 3 y busca por nombre exacto

struct Estudiante {
    char nombre[40];
    int edad;
    float promedio;
};

void ejercicio5() {
    int n;
    cout << "Cantidad de estudiantes: ";
    cin >> n;
    cin.ignore(); // limpia salto de línea

    Estudiante e[50]; // arreglo de hasta 50 estudiantes

    // --- Leer datos ---
    for (int i = 0; i < n; i++) {
        cout << "\nNombre: ";
        cin.getline(e[i].nombre, 40);
        cout << "Edad: ";
        cin >> e[i].edad;
        cout << "Promedio: ";
        cin >> e[i].promedio;
        cin.ignore(); // limpia salto de línea para la próxima lectura
    }

    // --- Ordenar por promedio (burbuja descendente) ---
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].promedio < e[j + 1].promedio) {
                Estudiante temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    // --- Mostrar el top 3 ---
    cout << "\n--- Top 3 por promedio ---\n";
    int limite = (n < 3) ? n : 3;
    for (int i = 0; i < limite; i++) {
        cout << i + 1 << ". " << e[i].nombre
             << " - Promedio: " << e[i].promedio << endl;
    }

    // --- Búsqueda por nombre exacto ---
    char buscar[40];
    cout << "\nIngresa el nombre a buscar: ";
    cin.getline(buscar, 40);

    int indice = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(e[i].nombre, buscar) == 0) {
            indice = i; // encontrado
            break;
        }
    }

    cout << "Resultado de busqueda: " << indice << endl;
}

// ====== EJERCICIO 6 ======
struct Nodo {
    int dato;
    Nodo* sig;
};

void insertarInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->sig = cabeza;
    cabeza = nuevo;
}

void insertarFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->sig = nullptr;
    if (cabeza == nullptr) cabeza = nuevo;
    else {
        Nodo* actual = cabeza;
        while (actual->sig) actual = actual->sig;
        actual->sig = nuevo;
    }
}

void eliminarInicio(Nodo*& cabeza) {
    if (!cabeza) {
        cout << "La lista esta vacia.\n";
        return;
    }
    Nodo* temp = cabeza;
    cabeza = cabeza->sig;
    delete temp;
}

void mostrarLista(Nodo* cabeza) {
    if (!cabeza) {
        cout << "La lista esta vacia.\n";
        return;
    }
    cout << "Lista: ";
    while (cabeza) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->sig;
    }
    cout << endl;
}

void liberarLista(Nodo*& cabeza) {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->sig;
        delete temp;
    }
}

void ejercicio6() {
    Nodo* cabeza = nullptr;
    int op, valor;
    do {
        cout << "\n--- MENU LISTA SIMPLE ---\n"
             << "1. Insertar al inicio\n"
             << "2. Insertar al final\n"
             << "3. Eliminar primero\n"
             << "4. Mostrar lista\n"
             << "0. Salir\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: cout << "Valor: "; cin >> valor; insertarInicio(cabeza, valor); break;
            case 2: cout << "Valor: "; cin >> valor; insertarFinal(cabeza, valor); break;
            case 3: eliminarInicio(cabeza); break;
            case 4: mostrarLista(cabeza); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (op != 0);
    liberarLista(cabeza);
}

// ====== EJERCICIO 7 ======
int doble(int x) { return x * 2; }
int cuadrado(int x) { return x * x; }

void aplicar(int a[], int n, int (*func)(int)) {
    for (int i = 0; i < n; i++)
        a[i] = func(a[i]);
}

void ejercicio7() {
    int n;
    cout << "Cantidad de numeros: ";
    cin >> n;
    int v[50];
    for (int i = 0; i < n; i++) cin >> v[i];

    int opcion;
    cout << "1. Doble\n2. Cuadrado\nElige una opcion: ";
    cin >> opcion;

    if (opcion == 1) aplicar(v, n, doble);
    else aplicar(v, n, cuadrado);

    cout << "Resultado: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

// ====== EJERCICIO 8 ======
struct Venta {
    char producto[30];
    int unidades;
    float precio;
};

void ejercicio8() {
    int n;
    cout << "Cantidad de registros de venta: ";
    cin >> n;
    cin.ignore();

    Venta v[50];
    float total = 0;
    for (int i = 0; i < n; i++) {
        cout << "\nProducto: ";
        cin.getline(v[i].producto, 30);
        cout << "Unidades vendidas: ";
        cin >> v[i].unidades;
        cout << "Precio unitario: ";
        cin >> v[i].precio;
        cin.ignore();
        total += v[i].unidades * v[i].precio;
    }

    cout << "\nTotal vendido: $" << total << endl;

    // Producto más vendido
    int maxU = v[0].unidades;
    char masVendido[30];
    strcpy(masVendido, v[0].producto);

    for (int i = 1; i < n; i++) {
        if (v[i].unidades > maxU) {
            maxU = v[i].unidades;
            strcpy(masVendido, v[i].producto);
        }
    }

    cout << "Producto mas vendido: " << masVendido << endl;
    cout << "Promedio por venta: $" << total / n << endl;
}

// ====== MENÚ PRINCIPAL ======
int main() {
    int opcion;
    do {
        cout << "\n===== TALLER INTEGRAL C++ =====\n"
             << "1. Min, max y promedio\n"
             << "2. Rotar arreglo\n"
             << "3. Normalizar frase\n"
             << "4. Suma filas y columnas\n"
             << "5. Estudiantes\n"
             << "6. Lista simple\n"
             << "7. Operaciones con funciones\n"
             << "8. Ventas totales\n"
             << "0. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}