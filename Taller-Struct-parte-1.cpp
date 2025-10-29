/*
 * Taller Struct Parte 1
 * Ejercicios 1, 2 y 3
 * Cristian Andres Vargas
 * 
 * Contenido:
 * 1. Struct con constructores y valores por defecto
 * 2. Métodos const y validación
 * 3. Operadores == y < para ordenar y buscar
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* ============================================================
 * EJERCICIO 1: STRUCT CON CONSTRUCTORES Y VALORES POR DEFECTO
 * ============================================================ */

struct Producto1 {
    string nombre;
    double precio;
    int stock;

    // Constructor con parámetros por defecto
    Producto1(string n, double p = 0.0, int s = 0) {
        nombre = n;
        precio = p;
        stock = s;
    }
};

// Función para mostrar información del producto
void mostrarProducto1(const Producto1& p) {
    cout << fixed << setprecision(2);
    cout << "   Nombre: " << p.nombre << "\n";
    cout << "   Precio: $" << p.precio << "\n";
    cout << "   Stock: " << p.stock << " unidades\n";
}

void ejecutarEjercicio1() {
    cout << "=== EJERCICIO 1: STRUCT CON CONSTRUCTORES Y VALORES POR DEFECTO ===\n\n";

    Producto1 p1("Laptop", 1200.50, 10);
    Producto1 p2("Mouse", 25.99);   // stock usa valor por defecto
    Producto1 p3("Teclado");        // precio y stock por defecto

    cout << "Producto 1:\n"; mostrarProducto1(p1);
    cout << "\nProducto 2:\n"; mostrarProducto1(p2);
    cout << "\nProducto 3:\n"; mostrarProducto1(p3);

    cout << "\nEl Ejercicio 1 funciona correctamente\n\n";
}

/* =======================================
 * EJERCICIO 2: MÉTODOS CONST Y VALIDACIÓN
 * ======================================= */

struct Producto2 {
    string nombre;
    double precio;
    int stock;

    Producto2(string n, double p = 0.0, int s = 0) {
        nombre = n;
        precio = p;
        stock = s;
    }

    bool disponible() const {
        return stock > 0;
    }

    bool esValido() const {
        return (precio >= 0) && (!nombre.empty());
    }
};

void mostrarProducto2(const Producto2& p) {
    cout << fixed << setprecision(2);
    cout << "   Nombre: " << p.nombre << "\n";
    cout << "   Precio: $" << p.precio << "\n";
    cout << "   Stock: " << p.stock << "\n";
    cout << "   Disponible: " << (p.disponible() ? "Sí" : "No") << "\n";
    cout << "   Válido: " << (p.esValido() ? "Sí" : "No") << "\n";
}

void ejecutarEjercicio2() {
    cout << "=== EJERCICIO 2: MÉTODOS CONST Y VALIDACIÓN ===\n\n";

    Producto2 productos2[5] = {
        {"Laptop", 1200.50, 5},
        {"Mouse", -10.0, 15},     // precio inválido
        {"", 25.0, 0},            // nombre vacío
        {"Monitor", 200.00, 0},
        {"Teclado", 45.50, 10}
    };

    cout << "Lista completa de productos:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nProducto " << (i + 1) << ":\n";
        mostrarProducto2(productos2[i]);
    }

    cout << "\n=== PRODUCTOS VÁLIDOS ===\n";
    bool hayValidos = false;

    for (int i = 0; i < 5; i++) {
        if (productos2[i].esValido()) {
            cout << "\nProducto válido " << (i + 1) << ":\n";
            mostrarProducto2(productos2[i]);
            hayValidos = true;
        }
    }

    if (!hayValidos)
        cout << "   No hay productos válidos.\n";

    cout << "\nEl Ejercicio 2 funciona correctamente\n\n";
}

/* ==================================================
 * EJERCICIO 3: OPERADORES == Y < (ORDENAR Y BUSCAR)
 * ================================================== */

struct Producto3 {
    string nombre;
    double precio;
    int stock;

    Producto3(string n = "", double p = 0.0, int s = 0) {
        nombre = n;
        precio = p;
        stock = s;
    }

    string aMinusculas(string texto) const {
        for (size_t i = 0; i < texto.length(); i++) {
            texto[i] = tolower(texto[i]);
        }
        return texto;
    }

    bool operator==(const Producto3& otro) const {
        return aMinusculas(nombre) == aMinusculas(otro.nombre);
    }

    bool operator<(const Producto3& otro) const {
        if (precio < otro.precio) return true;
        if (precio > otro.precio) return false;
        return nombre < otro.nombre;
    }
};

// Muestra información del producto
void mostrarProducto3(const Producto3& p) {
    cout << fixed << setprecision(2);
    cout << "   Nombre: " << p.nombre << "\n";
    cout << "   Precio: $" << p.precio << "\n";
    cout << "   Stock: " << p.stock << "\n";
}

// Ordena un array (por precio y luego nombre)
void ordenarProductos3(Producto3 arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                Producto3 temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Busca producto por nombre (sin importar mayúsculas)
int buscarProducto3(Producto3 arr[], int n, const string& nombreBuscado) {
    Producto3 buscado(nombreBuscado);
    for (int i = 0; i < n; i++) {
        if (arr[i] == buscado) {
            return i;
        }
    }
    return -1;
}

void ejecutarEjercicio3() {
    cout << "=== EJERCICIO 3: OPERADORES == Y < ===\n\n";

    const int n = 5;
    Producto3 productos3[n] = {
        {"Laptop", 1200.50, 5},
        {"mouse", 25.99, 50},
        {"Monitor", 200.00, 15},
        {"Teclado", 45.00, 10},
        {"auriculares", 45.00, 20}
    };

    cout << "Lista original:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << (i + 1) << ":\n";
        mostrarProducto3(productos3[i]);
    }

    ordenarProductos3(productos3, n);

    cout << "\n=== PRODUCTOS ORDENADOS ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << (i + 1) << ":\n";
        mostrarProducto3(productos3[i]);
    }

    string nombreBuscar;
    cout << "\nIngresa el nombre de un producto para buscar: ";
    cin >> nombreBuscar;

    int pos = buscarProducto3(productos3, n, nombreBuscar);

    if (pos != -1) {
        cout << "\nProducto encontrado:\n";
        mostrarProducto3(productos3[pos]);
    } else {
        cout << "\nProducto no encontrado.\n";
    }

    cout << "\nEl Ejercicio 3 funciona correctamente\n\n";
}

/* ================
 * FUNCIÓN PRINCIPAL
 * ================ */

int main() {
    cout << "=== TALLER STRUCT ===\n\n";

    ejecutarEjercicio1();
    ejecutarEjercicio2();
    ejecutarEjercicio3();

    cout << "=== FIN PARTE 1 ===\n";
    return 0;
}
