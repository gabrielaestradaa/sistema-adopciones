#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "mascota.h"
#include "ordenamiento.h"

using namespace std;

vector<Mascota> cargarMascotas(const string& archivo) {

    vector<Mascota> mascotas;
    ifstream entrada(archivo);

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo: " << archivo << endl;
        return mascotas;
    }

    string linea;
    while (getline(entrada, linea)) {

        if (linea.empty()) continue;

        stringstream ss(linea);
        string campo;
        vector<string> campos;

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos.size() < 6) continue;

        int id = stoi(campos[0]);
        string nombre = campos[1];
        string especie = campos[2];
        string raza = campos[3];
        int edad = stoi(campos[4]);
        string tamano = campos[5];

        mascotas.push_back(Mascota(id, nombre, especie, raza, edad, tamano));
    }

    entrada.close();
    return mascotas;
}

void mostrarTodas(vector<Mascota>& mascotas) {
    for (int i = 0; i < (int)mascotas.size(); i++) {
        mascotas[i].mostrar();
    }
}

void guardarMascotas(vector<Mascota>& mascotas, const string& archivo) {

    ofstream salida(archivo);

    if (!salida.is_open()) {
        cout << "No se pudo crear/abrir el archivo: " << archivo << endl;
        return;
    }

    for (int i = 0; i < (int)mascotas.size(); i++) {
        salida << mascotas[i].getId() << ","
               << mascotas[i].getNombre() << ","
               << mascotas[i].getEspecie() << ","
               << mascotas[i].getRaza() << ","
               << mascotas[i].getEdad() << ","
               << mascotas[i].getTamano() << "\n";
    }

    salida.close();
    cout << "Datos guardados en " << archivo << endl;
}

int main() {

    vector<Mascota> mascotas = cargarMascotas("mascotas.csv");

    if (mascotas.empty()) {
        cout << "No se cargaron mascotas. Verifica el archivo mascotas.csv" << endl;
        return 1;
    }

    int opcion = -1;

    while (opcion != 0) {
        cout << "\n ORDENAR MASCOTAS \n";
        cout << "1. Ordenar por Nombre\n";
        cout << "2. Ordenar por Edad\n";
        cout << "3. Ordenar por Especie\n";
        cout << "4. Ordenar por Raza\n";
        cout << "5. Mostrar sin ordenar (recargar desde archivo)\n";
        cout << "6. Guardar orden actual en mascotas_ordenado.csv\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mergeSortNombre(mascotas, 0, mascotas.size() - 1);
                mostrarTodas(mascotas);
                break;
            case 2:
                mergeSortEdad(mascotas, 0, mascotas.size() - 1);
                mostrarTodas(mascotas);
                break;
            case 3:
                mergeSortEspecie(mascotas, 0, mascotas.size() - 1);
                mostrarTodas(mascotas);
                break;
            case 4:
                mergeSortRaza(mascotas, 0, mascotas.size() - 1);
                mostrarTodas(mascotas);
                break;
            case 5:
                mascotas = cargarMascotas("mascotas.csv");
                mostrarTodas(mascotas);
                break;
            case 6:
                guardarMascotas(mascotas, "mascotas_ordenado.csv");
                break;
            case 0:
                cout << "Gracias por usar el sistema de adopciones.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }

    return 0;
}