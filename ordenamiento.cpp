#include "ordenamiento.h"

void mergeNombre(vector<Mascota>& mascotas, int inicio, int mitad, int fin) {

    vector<Mascota> izquierda(mascotas.begin() + inicio, mascotas.begin() + mitad + 1);
    vector<Mascota> derecha(mascotas.begin() + mitad + 1, mascotas.begin() + fin + 1);

    int i = 0, j = 0, k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        if (izquierda[i].getNombre() <= derecha[j].getNombre()) {
            mascotas[k] = izquierda[i];
            i++;
        } else {
            mascotas[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < (int)izquierda.size()) {
        mascotas[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < (int)derecha.size()) {
        mascotas[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSortNombre(vector<Mascota>& mascotas, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        mergeSortNombre(mascotas, inicio, mitad);
        mergeSortNombre(mascotas, mitad + 1, fin);
        mergeNombre(mascotas, inicio, mitad, fin);
    }
}

void mergeEdad(vector<Mascota>& mascotas, int inicio, int mitad, int fin) {

    vector<Mascota> izquierda(mascotas.begin() + inicio, mascotas.begin() + mitad + 1);
    vector<Mascota> derecha(mascotas.begin() + mitad + 1, mascotas.begin() + fin + 1);

    int i = 0, j = 0, k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        if (izquierda[i].getEdad() <= derecha[j].getEdad()) {
            mascotas[k] = izquierda[i];
            i++;
        } else {
            mascotas[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < (int)izquierda.size()) {
        mascotas[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < (int)derecha.size()) {
        mascotas[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSortEdad(vector<Mascota>& mascotas, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        mergeSortEdad(mascotas, inicio, mitad);
        mergeSortEdad(mascotas, mitad + 1, fin);
        mergeEdad(mascotas, inicio, mitad, fin);
    }
}


void mergeEspecie(vector<Mascota>& mascotas, int inicio, int mitad, int fin) {

    vector<Mascota> izquierda(mascotas.begin() + inicio, mascotas.begin() + mitad + 1);
    vector<Mascota> derecha(mascotas.begin() + mitad + 1, mascotas.begin() + fin + 1);

    int i = 0, j = 0, k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        if (izquierda[i].getEspecie() <= derecha[j].getEspecie()) {
            mascotas[k] = izquierda[i];
            i++;
        } else {
            mascotas[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < (int)izquierda.size()) {
        mascotas[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < (int)derecha.size()) {
        mascotas[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSortEspecie(vector<Mascota>& mascotas, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        mergeSortEspecie(mascotas, inicio, mitad);
        mergeSortEspecie(mascotas, mitad + 1, fin);
        mergeEspecie(mascotas, inicio, mitad, fin);
    }
}


void mergeRaza(vector<Mascota>& mascotas, int inicio, int mitad, int fin) {

    vector<Mascota> izquierda(mascotas.begin() + inicio, mascotas.begin() + mitad + 1);
    vector<Mascota> derecha(mascotas.begin() + mitad + 1, mascotas.begin() + fin + 1);

    int i = 0, j = 0, k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        if (izquierda[i].getRaza() <= derecha[j].getRaza()) {
            mascotas[k] = izquierda[i];
            i++;
        } else {
            mascotas[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < (int)izquierda.size()) {
        mascotas[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < (int)derecha.size()) {
        mascotas[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSortRaza(vector<Mascota>& mascotas, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        mergeSortRaza(mascotas, inicio, mitad);
        mergeSortRaza(mascotas, mitad + 1, fin);
        mergeRaza(mascotas, inicio, mitad, fin);
    }
}