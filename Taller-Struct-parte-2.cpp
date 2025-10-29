/* Taller Struct parte 2 (Motivo de haber dividido el ejercicio en dos partes es porque tuve infinitos errores en el codigo)
 * Ejercicios 4, 5, 6 y 7
 * 
 * Cristian Andres Vargas
 * 
 * Contenido:
 * 4. Estructura para representar un polinomio
 * 5. Sistema de inventario más complejo
 * 6. Estructura para representar una fracción
 * 7. Sistema de gestión de contactos
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* =========================================
 * EJERCICIO 4: ESTRUCTURA PARA UN POLINOMIO
 * ========================================= */

struct Termino {
    double coeficiente;
    int exponente;
};

struct Polinomio {
    Termino terminos[3];
    int cantidad;

    // Constructor básico
    Polinomio() {
        cantidad = 0;
    }

    void agregarTermino(double c, int e) {
        if (cantidad < 3) {
            terminos[cantidad].coeficiente = c;
            terminos[cantidad].exponente = e;
            cantidad++;
        }
    }

    void mostrar() const {
        cout << "   Polinomio: ";
        for (int i = 0; i < cantidad; i++) {
            cout << fixed << setprecision(1);
            cout << terminos[i].coeficiente << "x^" << terminos[i].exponente;
            if (i < cantidad - 1) cout << " + ";
        }
        cout << "\n";
    }
};

void ejecutarEjercicio4() {
    cout << "=== EJERCICIO 4: ESTRUCTURA PARA UN POLINOMIO ===\n\n";

    Polinomio p;
    p.agregarTermino(3.0, 2);
    p.agregarTermino(2.0, 1);
    p.agregarTermino(1.0, 0);

    p.mostrar();

    cout << "\nEl Ejercicio 4 funciona correctamente\n\n";
}

/* ================================================
 * EJERCICIO 5: SISTEMA DE INVENTARIO MÁS COMPLEJO
 * ================================================ */

struct ProductoInv {
    string nombre;
    string categoria;
    double precio;
    int stock;
    bool disponible;
};

void mostrarProductoInv(const ProductoInv& p) {
    cout << fixed << setprecision(2);
    cout << "   Nombre: " << p.nombre << "\n";
    cout << "   Categoría: " << p.categoria << "\n";
    cout << "   Precio: $" << p.precio << "\n";
    cout << "   Stock: " << p.stock << "\n";
    cout << "   Disponible: " << (p.disponible ? "Sí" : "No") << "\n";
}

void ejecutarEjercicio5() {
    cout << "=== EJERCICIO 5: SISTEMA DE INVENTARIO MÁS COMPLEJO ===\n\n";

    const int n = 3;
    ProductoInv inventario[n] = {
        {"Laptop", "Electrónica", 1200.0, 5, true},
        {"Silla Gamer", "Muebles", 750.0, 2, true},
        {"Cámara", "Fotografía", 0.0, 0, false}
    };

    cout << "Inventario de productos:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << (i + 1) << ":\n";
        mostrarProductoInv(inventario[i]);
    }

    cout << "\nEl Ejercicio 5 funciona correctamente\n\n";
}

/* ================================================
 * EJERCICIO 6: ESTRUCTURA PARA REPRESENTAR FRACCIÓN
 * ================================================ */

struct Fraccion {
    int numerador;
    int denominador;

    // Constructor
    Fraccion(int n = 0, int d = 1) {
        numerador = n;
        denominador = (d == 0) ? 1 : d; // evita división por cero
    }

    // Simplificar fracción
    int mcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplificar() {
        int divisor = mcd(numerador, denominador);
        numerador /= divisor;
        denominador /= divisor;
    }

    void mostrar() const {
        cout << "   Fracción: " << numerador << "/" << denominador << "\n";
    }
};

void ejecutarEjercicio6() {
    cout << "=== EJERCICIO 6: ESTRUCTURA PARA UNA FRACCIÓN ===\n\n";

    Fraccion f1(8, 12);
    cout << "Fracción original:\n";
    f1.mostrar();

    f1.simplificar();
    cout << "Fracción simplificada:\n";
    f1.mostrar();

    cout << "\nEl Ejercicio 6 funciona correctamente\n\n";
}

/* ============================================
 * EJERCICIO 7: SISTEMA DE GESTIÓN DE CONTACTOS
 * ============================================ */

struct Contacto {
    string nombre;
    string telefono;
    string correo;
};

void mostrarContacto(const Contacto& c) {
    cout << "   Nombre: " << c.nombre << "\n";
    cout << "   Teléfono: " << c.telefono << "\n";
    cout << "   Correo: " << c.correo << "\n";
}

void ejecutarEjercicio7() {
    cout << "=== EJERCICIO 7: SISTEMA DE GESTIÓN DE CONTACTOS ===\n\n";

    const int maxContactos = 3;
    Contacto agenda[maxContactos];

    // Cargar contactos (ejemplo rápido)
    agenda[0] = {"María López", "3105551122", "maria@example.com"};
    agenda[1] = {"Carlos Ruiz", "3158889911", "carlos@example.com"};
    agenda[2] = {"Ana Torres", "3007776655", "ana@example.com"};

    cout << "Contactos guardados:\n";
    for (int i = 0; i < maxContactos; i++) {
        cout << "\nContacto " << (i + 1) << ":\n";
        mostrarContacto(agenda[i]);
    }

    cout << "\nEl Ejercicio 7 funciona correctamente\n\n";
}

/* ================
 * FUNCIÓN PRINCIPAL
 * ================ */

int main() {
    cout << "=== TALLER STRUCT EN C++ (EJERCICIOS 4–7) ===\n\n";

    ejecutarEjercicio4();
    ejecutarEjercicio5();
    ejecutarEjercicio6();
    ejecutarEjercicio7();

    cout << "=== FIN DEL PROGRAMA ===\n";
    return 0;
}
