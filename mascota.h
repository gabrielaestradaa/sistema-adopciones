#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

using namespace std;

class Mascota {

private:
    int id;
    string nombre;
    string especie;
    string raza;
    int edad;
    string tamano;

public:
    Mascota();

    Mascota(int id, string nombre, string especie,
            string raza, int edad, string tamano);

    int getId();
    string getNombre();
    string getEspecie();
    string getRaza();
    int getEdad();
    string getTamano();

    void mostrar();
};

#endif