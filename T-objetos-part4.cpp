#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric> // Para std::accumulate

using namespace std;


//CLASE BASE: Persona


class Persona {
protected:
    string nombre;
    int edad;
    string cedula;

public:
    // Constructor
    Persona(string _nombre, int _edad, string _cedula) :
        nombre(_nombre), edad(_edad), cedula(_cedula) {}

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getCedula() const { return cedula; }

    // Setters con validaciones (ejemplo)
    void setEdad(int _edad) {
        if (_edad > 0) edad = _edad;
    }

    // Método virtual para polimorfismo
    virtual void mostrarInfo() const {
        cout << "\nINFORMACIÓN BASE (Persona)" << endl;
        cout << "  Nombre: " << nombre << endl;
        cout << "  Edad: " << edad << " años" << endl;
        cout << "  Cédula: " << cedula << endl;
    }

    // Destructor virtual
    virtual ~Persona() {}
};


//2. CLASES DERIVADAS de Persona


//CLASE ANIDADA (Para Estudiante)
class Curso {
private:
    string codigo;
    string nombre;
    int creditos;
    string profesor;
    double calificacion; // Calificación obtenida por el estudiante

public:
    Curso(string cod, string nom, int cred, string prof) :
        codigo(cod), nombre(nom), creditos(cred), profesor(prof), calificacion(0.0) {}

    // Getter para calificacion y creditos (necesarios para el promedio)
    double getCalificacion() const { return calificacion; }
    int getCreditos() const { return creditos; }
    string getNombre() const { return nombre; }

    // Setter de calificacion
    void setCalificacion(double nota) {
        if (nota >= 0.0 && nota <= 5.0) { // Asumimos escala de 0.0 a 5.0
            calificacion = nota;
        } else {
            cout << "ERROR: Calificación fuera de rango." << endl;
        }
    }

    void mostrarInfo() const {
        cout << "    > [" << codigo << "] " << nombre << " (" << creditos << " Créditos)" << endl;
        cout << "      Profesor: " << profesor << " | Nota: " << calificacion << endl;
    }
};


//CLASE DERIVADA: Estudiante
class Estudiante : public Persona {
private:
    string carrera;
    double promedio;
    int semestre;
    vector<Curso> cursosMatriculados;

public:
    // Constructor
    Estudiante(string _nombre, int _edad, string _cedula, string _carrera, int _semestre)
        : Persona(_nombre, _edad, _cedula), carrera(_carrera), semestre(_semestre), promedio(0.0) {}

    // Getters y Setters
    double getPromedio() const { return promedio; }
    void setCarrera(string _carrera) { carrera = _carrera; }

    // Método para matricular cursos
    void matricularCurso(const Curso& nuevoCurso) {
        cursosMatriculados.push_back(nuevoCurso);
        cout << "Hecho" << nombre << " matriculado en: " << nuevoCurso.getNombre() << endl;
    }

    // Método especial: Calcular el promedio ponderado
    double calcularPromedioActual() {
        double totalPuntos = 0.0;
        int totalCreditos = 0;

        for (const auto& curso : cursosMatriculados) {
            totalPuntos += curso.getCalificacion() * curso.getCreditos();
            totalCreditos += curso.getCreditos();
        }

        if (totalCreditos > 0) {
            promedio = totalPuntos / totalCreditos;
        } else {
            promedio = 0.0;
        }
        return promedio;
    }

    // Método para ver calificaciones
    void verCalificaciones() const {
        cout << "Calificaciones" << endl;
        for (const auto& curso : cursosMatriculados) {
            curso.mostrarInfo();
        }
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "  Rol: Estudiante" << endl;
        cout << "  Carrera: " << carrera << endl;
        cout << "  Semestre: " << semestre << endl;
        cout << fixed << setprecision(2);
        cout << "  Promedio: " << promedio << endl;
        cout << "  Cursos Matriculados: " << cursosMatriculados.size() << endl;
    }
};

//CLASE DERIVADA: Profesor
class Profesor : public Persona {
private:
    string especialidad;
    int aniosExperiencia;
    int numeroEstudiantes;

public:
    // Constructor
    Profesor(string _nombre, int _edad, string _cedula, string _esp, int _exp)
        : Persona(_nombre, _edad, _cedula), especialidad(_esp), aniosExperiencia(_exp), numeroEstudiantes(0) {}

    // Getters y Setters
    void setNumeroEstudiantes(int num) {
        if (num >= 0) numeroEstudiantes = num;
    }

    // Método especial: Verificar disponibilidad
    bool estaDisponible(int horaDelDia) const {
        // Asume disponibilidad entre 9 y 17 horas
        return (horaDelDia >= 9 && horaDelDia <= 17);
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "  Rol: Profesor" << endl;
        cout << "  Especialidad: " << especialidad << endl;
        cout << "  Años Experiencia: " << aniosExperiencia << endl;
        cout << "  N° Estudiantes a cargo: " << numeroEstudiantes << endl;
    }
};

//CLASE DERIVADA: Personal
class Personal : public Persona {
private:
    string puesto;
    string departamento;
    double salarioBase;

public:
    // Constructor
    Personal(string _nombre, int _edad, string _cedula, string _puesto, string _depto, double _salario)
        : Persona(_nombre, _edad, _cedula), puesto(_puesto), departamento(_depto) {
        if (_salario >= 0) salarioBase = _salario; else salarioBase = 0.0;
    }

    // Getters y Setters
    void setSalarioBase(double _salario) {
        if (_salario >= 0) salarioBase = _salario;
    }

    // Método especial: Calcular Salario Mensual (asume 12 pagas anuales)
    double calcularSalarioMensual() const {
        return salarioBase / 12.0;
    }

    // Sobrescritura de mostrarInfo()
    void mostrarInfo() const override {
        Persona::mostrarInfo();
        cout << "  --- Rol: Personal Administrativo ---" << endl;
        cout << "  Puesto: " << puesto << endl;
        cout << "  Departamento: " << departamento << endl;
        cout << fixed << setprecision(2);
        cout << "  Salario Base Anual: $" << salarioBase << endl;
    }
};

//MAIN
int main() {
    cout << "DESAFÍO - SISTEMA UNIVERSITARIO" << endl;

    // 1. Crear y probar clases
    
    // Crear Profesor
    Profesor prof1("Dr. Alberto Ruiz", 55, "123456", "Ingeniería de Software", 20);
    prof1.setNumeroEstudiantes(35);
    prof1.mostrarInfo();
    cout << "  ¿Disponible a las 14:00? " << (prof1.estaDisponible(14) ? "Sí" : "No") << endl;

    // Crear Personal
    Personal pers1("Laura Pérez", 30, "789012", "Asistente", "Recursos Humanos", 36000.0);
    pers1.mostrarInfo();
    cout << "  Salario Mensual Estimado: $" << pers1.calcularSalarioMensual() << endl;

    // Crear Estudiante
    Estudiante est1("Juan Cifuentes", 20, "345678", "Ciencias de la Computación", 5);
    
    // 2. Probar cursos y promedio (Composición)
    cout << "\n--- Operaciones con Estudiante ---" << endl;
    
    // Definición de Cursos
    Curso curso1("CS101", "POO con C++", 3, prof1.getNombre());
    Curso curso2("MT205", "Álgebra Lineal", 4, "Dra. Gómez");
    
    est1.matricularCurso(curso1);
    est1.matricularCurso(curso2);
    
    // Poner calificaciones
    // Nota: Para modificar la calificación, necesitamos acceder al curso en el vector
    // Se usa un getter para obtener la referencia al vector de cursos.
    // (Simplificamos la modificación con un índice para la prueba)
    
    // Poner notas (calificaciones de 0.0 a 5.0)
    // El curso 1 (POO)
    est1.getPromedio(); // Llamada inicial para calcular 0.0
    // Asumimos que la clase Estudiante tendrá un método para modificar calificaciones:
    
    // Nota: Como no se definió un setter dentro de Estudiante para el curso, lo haremos de forma simple:
    
    // En un sistema real, se accedería a la lista de cursos y se modificaría la nota.
    // Aquí simularemos las notas antes de calcular el promedio final.
    // Para una solución limpia, Estudiante debería tener un método: asignarCalificacion(codigo, nota)
    
    // *** SIMULACIÓN DE ASIGNACIÓN DE NOTAS ***
    // (Necesitaríamos modificar la clase Estudiante para permitir modificar las calificaciones de sus cursos)
    
    // Versión 2: Modificación directa de un objeto Curso temporal
    Curso curso_temp1("CS101", "POO con C++", 3, prof1.getNombre());
    curso_temp1.setCalificacion(4.5); // 4.5
    
    Curso curso_temp2("MT205", "Álgebra Lineal", 4, "Dra. Gómez");
    curso_temp2.setCalificacion(3.0); // 3.0
    
    // Creamos un nuevo estudiante con las notas ya puestas (simplificación para el test)
    Estudiante est2("Maria Lopez", 21, "999000", "Matemáticas", 6);
    est2.matricularCurso(curso_temp1);
    est2.matricularCurso(curso_temp2);
    
    // Calcular promedio (ejemplo ponderado: (4.5*3 + 3.0*4) / (3+4) = (13.5 + 12) / 7 = 3.64)
    est2.calcularPromedioActual();
    est2.mostrarInfo();
    est2.verCalificaciones();

    return 0;
}