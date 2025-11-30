#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//TALLER OBJETOS EJERCICIOS PARTE 1

//EJERCICIO 1.1: CLASE VEHÍCULO

class Vehiculo {
private:
    // Atributos (privados) 
    string marca;
    string modelo;
    int anio;
    double velocidadMaxima;

public:
    // Constructo que inicia todos los atributos
    Vehiculo(string _marca, string _modelo, int _anio, double _velocidadMaxima) :
        marca(_marca), modelo(_modelo) {
        // Usamos los setters para aplicar las validaciones
        setAnio(_anio);
        setVelocidadMaxima(_velocidadMaxima);
    }

    //Getters
    string getMarca() const {
        return marca;
    }

    string getModelo() const {
        return modelo;
    }

    int getAnio() const {
        return anio;
    }

    double getVelocidadMaxima() const {
        return velocidadMaxima;
    }

    //Setters con validaciones
    void setMarca(string _marca) {
        marca = _marca;
    }

    void setModelo(string _modelo) {
        modelo = _modelo;
    }

    // El año debe ser mayor a 1886
    void setAnio(int _anio) {
        if (_anio > 1886) {
            anio = _anio;
        } else {
            cout<<"ERROR: El año del vehículo debe ser mayor a 1886. Se mantuvo el año anterior."<<endl;
        }
    }

    // La velocidad máxima debe ser positiva
    void setVelocidadMaxima(double _velocidadMaxima) {
        if (_velocidadMaxima > 0) {
            velocidadMaxima = _velocidadMaxima;
        } else {
            cout<<"ERROR: La velocidad máxima debe ser positiva. Se mantuvo el valor anterior"<<endl;
        }
    }

    // Método que aumenta la velocidad máxima
    void acelerar(double incremento) {
        if (incremento > 0) {
            velocidadMaxima += incremento;
            cout<<"Velocidad máxima aumentada en "<<incremento<<" km/h."<<endl;
        } else {
            cout<<"ERROR: El incremento de velocidad debe ser positivo."<<endl;
        }
    }

    //imprimir todos los datos del vehículo
    void mostrarInfo() const {
        cout<<"\n--- Información del Vehículo ---"<<endl;
        cout<<"  Marca: " <<marca<<endl;
        cout<<"  Modelo: "<<modelo<<endl;
        cout<<"  Año: "<<anio<<endl;
        cout<<fixed << setprecision(2); // Para mostrar 2 decimales
        cout<<"  Velocidad Máxima: "<<velocidadMaxima<< " km/h"<<endl;
    }
};

//EJERCICIO 1.2: CLASE PRODUCTO

class Producto {
private:
    // Atributos privados
    string codigo;
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor inicializador
    Producto(string _codigo, string _nombre, double _precio, int _cantidad) :
        codigo(_codigo), nombre(_nombre) {
        // Usamos los setters para aplicar las validaciones
        setPrecio(_precio);
        setCantidad(_cantidad);
    }

    //Getters
    string getCodigo() const {
        return codigo;
    }

    string getNombre() const {
        return nombre;
    }

    double getPrecio() const {
        return precio;
    }

    int getCantidad() const {
        return cantidad;
    }

    //Setters con validaciones
    void setCodigo(string _codigo) {
        codigo = _codigo;
    }

    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    // Precio no puede ser negativo
    void setPrecio(double _precio) {
        if (_precio >= 0) {
            precio = _precio;
        } else {
            cout<<"ERROR: El precio no puede ser negativo. Se mantuvo el valor anterior/por defecto."<<endl;
        }
    }

    // Cantidad no puede ser negativa
    void setCantidad(int _cantidad) {
        if (_cantidad >= 0) {
            cantidad = _cantidad;
        } else {
            cout<<"ERROR: La cantidad no puede ser negativa. Se mantuvo el valor anterior/por defecto."<<endl;
        }
    }

    // Método que retorna precio × cantidad
    double calcularValorTotal() const {
        return precio * cantidad;
    }

    // Método que reduce el precio según un porcentaje
    void aplicarDescuento(double porcentaje) {
        if (porcentaje >= 0 && porcentaje <= 100) {
            double factorDescuento=1.0-(porcentaje / 100.0);
            precio*=factorDescuento;
            cout<<"Descuento del "<<porcentaje<<"% aplicado correctamente."<<endl;
        } else {
            cout<<"ERROR: El porcentaje de descuento debe estar entre 0 y 100."<<endl;
        }
    }

    //Método que muestra todos los datos del producto
    void mostrarInfo() const {
        cout<<"\n--- Información del Producto ---"<<endl;
        cout<<"  Código: "<<codigo<<endl;
        cout<<"  Nombre: "<<nombre<<endl;
        cout<<fixed << setprecision(2);
        cout<<"  Precio Unitario: $"<<precio<<endl;
        cout<<"  Cantidad en Stock: "<<cantidad<<endl;
    }
};

//FUNCIÓN MAIN

int main() {
    // Prueba de la Clase Vehículo (Ejercicio 1.1)
    cout<<"PRUEBA - CLASE VEHÍCULO"<<endl;
    
    // Ejemplo del uso del ejercicio:
    Vehiculo autoEjemplo("Toyota", "Corolla", 2023, 180.0);
    autoEjemplo.mostrarInfo();
    
    // Prueba de acelerar y validación
    autoEjemplo.acelerar(20.0);
    autoEjemplo.setAnio(1800); // Esto debe fallar por la validación
    autoEjemplo.setVelocidadMaxima(-5.0); // Esto debe fallar
    autoEjemplo.mostrarInfo(); // Se muestra la información actualizada



    // Prueba de la Clase Producto (Ejercicio 1.2)
    cout<<"\n\nPRUEBA - CLASE PRODUCTO"<<endl;
    
    // Ejemplo del uso de el Ejercicio:
    Producto laptop("001", "Laptop HP", 850.00, 5);
    laptop.mostrarInfo();
    
    // Cálculo de valor total
    cout<<fixed<<setprecision(2);
    cout<<"Valor total en stock: $"<<laptop.calcularValorTotal()<<endl;
    
    // Prueba de descuento y validación
    laptop.aplicarDescuento(10); // 10% de descuento
    laptop.setPrecio(-100.0); // Esto debe fallar por la validación
    laptop.setCantidad(-2); // Esto debe fallar
    laptop.mostrarInfo();
    
    // Nuevo cálculo de valor total
    cout<<"Nuevo valor total en stock: $"<<laptop.calcularValorTotal()<<endl;

    return 0;
}