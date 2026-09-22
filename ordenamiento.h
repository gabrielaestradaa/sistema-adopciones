#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>
#include "mascota.h"

using namespace std;


void mergeNombre(vector<Mascota>& mascotas,
                 int inicio,
                 int mitad,
                 int fin);

void mergeSortNombre(vector<Mascota>& mascotas,
                     int inicio,
                     int fin);


void mergeEdad(vector<Mascota>& mascotas,
               int inicio,
               int mitad,
               int fin);

void mergeSortEdad(vector<Mascota>& mascotas,
                   int inicio,
                   int fin);



void mergeEspecie(vector<Mascota>& mascotas,
                  int inicio,
                  int mitad,
                  int fin);

void mergeSortEspecie(vector<Mascota>& mascotas,
                      int inicio,
                      int fin);



void mergeRaza(vector<Mascota>& mascotas,
               int inicio,
               int mitad,
               int fin);

void mergeSortRaza(vector<Mascota>& mascotas,
                   int inicio,
                   int fin);

#endif