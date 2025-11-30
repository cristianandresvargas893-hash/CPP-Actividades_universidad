#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//CLASE BASE: Vehiculo (Del Ejercicio 1.1)

class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio;
    double velocidadMaxima;

public:
    // Constructor
    Vehiculo(string _marca, string _modelo, int _anio, double _velocidadMaxima) :
        marca(_marca), modelo(_modelo), velocidadMaxima(_velocidadMaxima) {
        // Validación simple para el año y velocidad, asumida del 1.1
        if (_anio > 1886) { anio = _anio; } else { anio = 1887; }
        if (_velocidadMaxima > 0) { velocidadMaxima = _velocidadMaxima; } else { velocidadMaxima = 1; }
    }

    // Método virtual para permitir el polimorfismo (sobrescritura)
    virtual void mostrarInfo() const {
        cout<<"\n--- Vehículo Base ---"<<endl;
        cout<<"  Marca: "<<marca<<endl;
        cout<<"  Modelo: "<<modelo<<endl;
        cout<<"  Año: "<<anio<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"  Velocidad Máxima: "<<velocidadMaxima<<" km/h"<<endl;
    }

    // Destructor virtual (Buena práctica en clases base con métodos virtuales)
    virtual ~Vehiculo() {}
};

//EJERCICIO 2.1: CLASES DERIVADAS de Vehiculo

//Clase Auto
class Auto : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    // Constructor que llama al constructor de la clase base
    Auto(string _marca, string _modelo, int _anio, double _vMax, int _puertas, string _combustible)
        : Vehiculo(_marca, _modelo, _anio, _vMax),
          numeroPuertas(_puertas), tipoCombustible(_combustible) {}

    // Getters
    int getNumeroPuertas() const { return numeroPuertas; }
    string getTipoCombustible() const { return tipoCombustible; }

    // Setters (con validación simple)
    void setNumeroPuertas(int puertas) {
        if (puertas > 0) numeroPuertas = puertas;
    }
    void setTipoCombustible(string combustible) { tipoCombustible = combustible; }

    // Sobrescritura (override) del método mostrarInfo()
    void mostrarInfo() const override {
        cout<<"\nAuto (Hereda de Vehículo)"<<endl;
        // Reutilizamos la info base o la imprimimos directamente usando 'protected'
        cout<<"  Marca: "<<marca<<", Modelo: "<<modelo<<", Año: "<<anio<<endl;
        cout<<"  Vel. Máxima: "<<velocidadMaxima<<" km/h"<<endl;
        cout<<"  Puertas: "<<numeroPuertas<<endl;
        cout<<"  Combustible: "<<tipoCombustible<<endl;
    }
};

//Clase Motocicleta
class Motocicleta : public Vehiculo {
private:
    bool tieneAlarma;
    int cilindrada;

public:
    // Constructor que llama al constructor de la clase base
    Motocicleta(string _marca, string _modelo, int _anio, double _vMax, bool _alarma, int _cilindrada)
        : Vehiculo(_marca, _modelo, _anio, _vMax),
          tieneAlarma(_alarma), cilindrada(_cilindrada) {}

    // Getters
    bool getTieneAlarma() const { return tieneAlarma; }
    int getCilindrada() const { return cilindrada; }

    // Setters (con validación simple)
    void setTieneAlarma(bool alarma) { tieneAlarma = alarma; }
    void setCilindrada(int cc) {
        if (cc > 0) cilindrada = cc;
    }

    // Sobrescritura (override) del método mostrarInfo()
    void mostrarInfo() const override {
        cout<<"\n--- Motocicleta (Hereda de Vehículo) ---"<<endl;
        cout<<"  Marca: "<<marca<<", Modelo: "<<modelo<<", Año: "<<anio<<endl;
        cout<<"  Vel. Máxima: "<<velocidadMaxima<<" km/h"<<endl;
        cout<<"  Alarma: "<<(tieneAlarma ? "Sí" : "No")<<endl;
        cout<<"  Cilindrada (cc): "<<cilindrada<<endl;
    }
};


//CLASE BASE: Empleado


class Empleado {
protected:
    string nombreCompleto;
    string numeroEmpleado;
    double salarioBase;

public:
    // Constructor
    Empleado(string _nombre, string _numEmpleado, double _salarioBase) :
        nombreCompleto(_nombre), numeroEmpleado(_numEmpleado) {
        if (_salarioBase >= 0) { salarioBase = _salarioBase; } else { salarioBase = 0.0; }
    }

    
    virtual double calcularSalarioTotal() const = 0;
    
    // Método virtual para mostrar información
    virtual void mostrarInfo() const {
        cout<<"\n--- Empleado Base ---"<<endl;
        cout<<"  Nombre: "<<nombreCompleto<<endl;
        cout<<"  Número de Empleado: "<<numeroEmpleado<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"  Salario Base: $"<<salarioBase<<endl;
    }
    
    virtual ~Empleado() {} // Destructor virtual

    // Getters y Setters (simplificados)
};

//EJERCICIO 2.2: CLASES DERIVADAS de Empleado

//Clase Empleadotiempo Completo
class EmpleadoTiempoCompleto : public Empleado {
private:
    string beneficios;
    double bono;

public:
    // Constructor
    EmpleadoTiempoCompleto(string _nombre, string _numEmpleado, double _salBase, string _beneficios, double _bono)
        : Empleado(_nombre, _numEmpleado, _salBase) {
        if (_bono >= 0) { bono = _bono; } else { bono = 0.0; }
        beneficios = _beneficios;
    }

    // Implementación obligatoria de la función virtual pura
    double calcularSalarioTotal() const override {
        return salarioBase + bono;
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        cout<<"\n--- Empleado a Tiempo Completo ---"<<endl;
        cout<<"  Nombre: "<<nombreCompleto<<", N°: "<<numeroEmpleado<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"  Salario Base: $"<<salarioBase<<", Bono: $"<<bono<<endl;
        cout<<"  Beneficios: "<<beneficios<<endl;
    }
};

//Clase Empleado Por Horas
class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    //Constructor
    EmpleadoPorHoras(string _nombre, string _numEmpleado, double _salBase, int _horas, double _tarifa)
        : Empleado(_nombre, _numEmpleado, _salBase) {
        if (_horas >= 0) { horasTrabajadas = _horas; } else { horasTrabajadas = 0; }
        if (_tarifa >= 0) { tarifaPorHora = _tarifa; } else { tarifaPorHora = 0.0; }
    }

    //Implementación obligatoria de la función virtual pura
    double calcularSalarioTotal() const override {
        return horasTrabajadas * tarifaPorHora;
    }

    //Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        cout<<"\n--- Empleado por Horas ---"<<endl;
        cout<<"  Nombre: "<<nombreCompleto<<", N°: "<<numeroEmpleado<<endl;
        cout<<fixed << setprecision(2);
        cout<<"  Horas Trabajadas: "<<horasTrabajadas<<", Tarifa/hr: $"<<tarifaPorHora<<endl;
    }
};


//FUNCIÓN MAIN
int main() {
    
    //Prueba Ejercicio 2.1: Herencia de Vehiculo
    cout<<"PRUEBA - JERARQUÍA VEHÍCULOS"<<endl;

    Auto miAuto("Ford", "Mustang", 2023, 220.0, 4, "Gasolina");
    Motocicleta miMoto("Harley-Davidson", "Sportster", 2023, 200.0, true, 1200);

    //Los métodos mostrarInfo() invocan a la versión sobrescrita
    miAuto.mostrarInfo();
    miMoto.mostrarInfo();
    
    
    // Prueba Ejercicio 2.2: Herencia de Empleado
    cout<<"\n\nPRUEBA - SISTEMA DE EMPLEADOS"<<endl;

    EmpleadoTiempoCompleto emp1("Juan López", "001", 2000.0, "Seguro médico completo", 500.0);
    EmpleadoPorHoras emp2("María García", "002", 0.0, 40, 15.0);

    emp1.mostrarInfo();
    cout<<"Salario Total (T. Completo): $"<<emp1.calcularSalarioTotal()<<endl;

    emp2.mostrarInfo();
    cout<<"Salario Total (Por Horas): $"<<emp2.calcularSalarioTotal()<<endl;

    return 0;
}