#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


//EJERCICIO 3.1: JERARQUÍA DE ANIMALES


//CLASE BASE: Animal
class Animal {
protected:
    string nombre;
    int edad;
    double peso;

public:
    //Constructor
    Animal(string _nombre, int _edad, double _peso) :
        nombre(_nombre), edad(_edad) {
        if (_peso > 0) peso = _peso; else peso = 0.1;
    }

    //Métodos virtuales puros (Clase Abstracta)
    virtual void hacerSonido() const = 0;
    virtual void mostrarInfo() const = 0;

    //Getters y Setters (solo un ejemplo de Setter con validación)
    void setEdad(int _edad) {
        if (_edad >= 0) edad = _edad;
    }

    //Destructor virtual
    virtual ~Animal() {}
};

//CLASE INTERMEDIA: Mamífero hereda de Animal
class Mamifero : public Animal {
protected:
    bool tieneColaMamifero;

public:
    //Constructor
    Mamifero(string _nombre, int _edad, double _peso, bool _tieneCola) :
        Animal(_nombre, _edad, _peso), tieneColaMamifero(_tieneCola) {}

    //Sobrescritura de mostrarInfo() (Parcialmente implementado aquí, se completa en subclases)
    void mostrarInfo() const override {
        cout<<"  (Tipo: Mamífero)"<<endl;
        cout<<"  Nombre: "<<nombre<<", Edad: "<<edad<<" años, Peso: "<<peso<<" kg"<<endl;
        cout<<"  Tiene Cola: "<<(tieneColaMamifero ? "Sí" : "No")<<endl;
    }
};

//CLASE INTERMEDIA: Ave hereda de Animal
class Ave : public Animal {
protected:
    double envergaduraAlas; // En metros

public:
    // Constructor
    Ave(string _nombre, int _edad, double _peso, double _envergadura) :
        Animal(_nombre, _edad, _peso) {
        if (_envergadura > 0) envergaduraAlas = _envergadura; else envergaduraAlas = 0.1;
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        cout<<"  (Tipo: Ave)"<<endl;
        cout<<"  Nombre: "<<nombre<<", Edad: "<<edad<<" años, Peso: "<<peso<<" kg"<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"  Envergadura de Alas: "<<envergaduraAlas<<" m"<<endl;
    }
    
};

//CLASES FINALES (Nivel 3)

class Perro : public Mamifero {
public:
    Perro(string _nombre, int _edad, double _peso, bool _tieneCola) : Mamifero(_nombre, _edad, _peso, _tieneCola) {}
    void hacerSonido() const override { cout<<"  Sonido: ¡Guau! ¡Guau!"<<endl; }
    void mostrarInfo() const override {
        cout<<"\n--- PERRO (Clase Final) ---"<<endl;
        Mamifero::mostrarInfo();
    }
};

class Loro : public Ave {
public:
    Loro(string _nombre, int _edad, double _peso, double _envergadura) : Ave(_nombre, _edad, _peso, _envergadura) {}
    void hacerSonido() const override { cout<<"  Sonido: ¡Hola! (Imita voz)"<<endl; }
    void mostrarInfo() const override {
        cout<<"\n--- LORO (Clase Final) ---"<<endl;
        Ave::mostrarInfo();
    }
};



//EJERCICIO 3.2: SISTEMA BANCARIO


//CLASE BASE: Cuenta
class Cuenta {
protected:
    string numeroCuenta;
    string propietario;
    double saldo;

public:
    //Constructor
    Cuenta(string _num, string _prop, double _saldo) :
        numeroCuenta(_num), propietario(_prop) {
        if (_saldo >= 0) saldo = _saldo; else saldo = 0.0;
    }

    //Métodos virtuales puros (Clase Abstracta)
    virtual void depositar(double monto) = 0;
    virtual void retirar(double monto) = 0;

    //Método virtual (no puro, puede tener implementación base)
    virtual void mostrarInfo() const {
        cout<<fixed<<setprecision(2);
        cout<<"\n--- CUENTA BASE ---"<<endl;
        cout<<"  N° Cuenta: "<<numeroCuenta<<endl;
        cout<<"  Propietario: "<<propietario<<endl;
        cout<<"  Saldo Actual: $"<<saldo<<endl;
    }

    // Getters
    double getSaldo() const { return saldo; }

    // Destructor virtual
    virtual ~Cuenta() {}
};

// --- CLASE DERIVADA: CuentaAhorro ---
class CuentaAhorro : public Cuenta {
private:
    double tasaInteres; // Ej: 0.02 (2%)

public:
    // Constructor
    CuentaAhorro(string _num, string _prop, double _saldo, double _tasa) :
        Cuenta(_num, _prop, _saldo) {
        if (_tasa >= 0) tasaInteres = _tasa; else tasaInteres = 0.0;
    }

    // Sobrescritura de depositar()
    void depositar(double monto) override {
        if (monto > 0) {
            saldo += monto;
            cout<<"EPÓSITO en Cuenta de Ahorro: $"<<monto<<". Saldo: $"<<saldo<<endl;
        } else {
            cout<<"ERROR: El monto a depositar debe ser positivo. no seas boludo man" << endl;
        }
    }

    // Sobrescritura de retirar()
    void retirar(double monto) override {
        if (monto > 0) {
            if (saldo >= monto) {
                saldo -= monto;
                cout<<"RETIRO de Cuenta de Ahorro: $"<<monto<<". Saldo: $"<<saldo<<endl;
            } else {
                cout<<"ERROR: Saldo insuficiente para retirar $"<<monto<<endl;
            }
        } else {
            cout<<"ERROR: El monto a retirar debe ser positivo."<<endl;
        }
    }

    // Método específico
    void generarInteres() {
        double interesGenerado = saldo * tasaInteres;
        saldo += interesGenerado;
        cout<<"Interés generado ("<<(tasaInteres * 100)<<"%): $"<<interesGenerado<<endl;
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        Cuenta::mostrarInfo();
        cout<<"  Tasa de Interés: "<<(tasaInteres * 100)<<"%"<<endl;
        cout<<"  TIPO: Cuenta de Ahorro"<<endl;
    }
};

// --- CLASE DERIVADA: CuentaCorriente ---
class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;

public:
    // Constructor
    CuentaCorriente(string _num, string _prop, double _saldo, double _limite) :
        Cuenta(_num, _prop, _saldo) {
        if (_limite >= 0) limiteDescubierto = _limite; else limiteDescubierto = 0.0;
    }

    // Sobrescritura de depositar()
    void depositar(double monto) override {
        if (monto > 0) {
            saldo += monto;
            cout<<"DEPÓSITO en Cuenta Corriente: $"<<monto<<". Saldo: $"<<saldo<<endl;
        } else {
            cout<<"ERROR: El monto a depositar debe ser positivo."<<endl;
        }
    }

    // Sobrescritura de retirar() (Permite descubierto)
    void retirar(double monto) override {
        if (monto > 0) {
            // El retiro es válido si el saldo no cae por debajo del límite de descubierto (negativo)
            if (saldo - monto >= -limiteDescubierto) {
                saldo -= monto;
                if (saldo < 0) {
                    cout<<" RETIRO (con Descubierto): $"<<monto<<". Nuevo Saldo: $"<<saldo<<endl;
                } else {
                    cout<<"RETIRO: $"<<monto<<". Nuevo Saldo: $"<<saldo<<endl;
                }
            } else {
                cout<<"EROR: El retiro de $"<<monto<<" excede el límite de descubierto de $"<<limiteDescubierto<<endl;
            }
        } else {
            cout<<"ERROR: El monto a retirar debe ser positivo."<<endl;
        }
    }

    // Método específico
    void solicitarDescubierto(double monto) {
        if (monto > 0 && monto <= limiteDescubierto) {
            cout<<" Se puede solicitar un descubierto de hasta $"<<monto<<" según el límite."<<endl;
        } else {
            cout<<" Solicitud inválida. El límite de descubierto es $"<<limiteDescubierto<<"."<<endl;
        }
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        Cuenta::mostrarInfo();
        cout<<"  Límite Descubierto: $"<<limiteDescubierto<<endl;
        cout<<"  TIPO: Cuenta Corriente"<<endl;
    }
};


//FUNCIÓN MAIN
int main() {
    // Prueba Ejercicio 3.1: Jerarquía Animales
    cout<<"PRUEBA - JERARQUÍA DE ANIMALES"<<endl;
    
    // Perro: Animal -> Mamífero -> Perro
    Perro perro("Rex", 5, 25.0, true);
    // Loro: Animal -> Ave -> Loro
    Loro loro("Tweety", 2, 0.5, 0.3);
    
    // Uso de Polimorfismo: Almacenamiento en vector de punteros a la clase base
    vector<Animal*> animales;
    animales.push_back(&perro);
    animales.push_back(&loro);

    for (const auto& animal : animales) {
        animal->mostrarInfo();
        animal->hacerSonido();
    }
    

    // Prueba Ejercicio 3.2: Sistema Bancario

    cout<<"\n\nPRUEBA - SISTEMA BANCARIO"<<endl;

    CuentaAhorro ahorros("123456", "Carlos", 5000.0, 0.02);
    CuentaCorriente corriente("789012", "Ana", 2000.0, 1000.0);

    //Cuenta Ahorro
    cout<<"\nOperaciones con Cuenta de Ahorro"<<endl;
    ahorros.depositar(1000.0);
    ahorros.mostrarInfo();
    ahorros.generarInteres();
    ahorros.mostrarInfo();

    //Cuenta Corriente
    cout<<"\nOperaciones con Cuenta Corriente"<<endl;
    corriente.retirar(2500.0); //Usa descubierto (saldo pasa de 2000 a -500)
    corriente.mostrarInfo();
    corriente.retirar(600.0); //Excede límite (saldo de -500 + retiro de 600 = -1100, excede -1000)
    corriente.mostrarInfo();

    //Ejemplo de uso de punteros base con polimorfismo
    cout<<"\nPolimorfismo con Cuentas" << endl;
    Cuenta* cuentaPtr = &corriente;
    cuentaPtr->retirar(100.0); //Retiro válido (saldo pasa a -600)
  return 0;
}