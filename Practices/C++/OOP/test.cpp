#include <iostream>

class Persona {
    public:
        std::string nombre;
        int edad;

        void imprimirInformacion(){
            std::cout << "Nombre: " << nombre << std::endl;
            std::cout << "Edad: " << edad << std::endl;
        }
};


int main() {
    Persona persona1;

    persona1.nombre = "Juan";
    persona1.edad = 30;


    persona1.imprimirInformacion();

    return 0;
}
