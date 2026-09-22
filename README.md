# sistema-adopciones
# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio
# Sistema de Adopciones

## Descripción

Este proyecto es un programa en C++ para organizar la información de mascotas de un refugio. El programa permite cargar los datos desde un archivo, mostrar las mascotas y ordenarlas por diferentes características.

## Problema que resuelve

Un refugio puede tener información de varias mascotas y puede ser difícil organizarla o encontrarla de diferentes formas. El programa permite mantener estos datos organizados y ordenarlos por nombre, edad, especie o raza para facilitar su consulta.

## Estructura de datos utilizada

Para guardar las mascotas se utiliza un `vector<Mascota>`, ya que permite almacenar varios objetos y acceder fácilmente a ellos.

También se utiliza la clase `Mascota`, que contiene los datos de cada mascota: ID, nombre, especie, raza, edad y tamaño.

## Algoritmo de ordenamiento

Se utilizó **Merge Sort** porque es uno de los algoritmos que vimos en clase y funciona bien para ordenar los datos del programa.

Merge Sort divide los datos en partes más pequeñas y después las vuelve a unir en el orden correcto. Su complejidad es **O(n log n)** en el mejor, promedio y peor caso.

En el programa se utiliza para ordenar las mascotas por nombre, edad, especie y raza.

## Lectura y escritura de archivos

Los datos se encuentran en el archivo `mascotas.txt`. Al iniciar el programa, se utiliza `ifstream` para leer la información y crear los objetos `Mascota`.

También se utiliza `ofstream` para guardar los datos nuevamente en el archivo cuando se selecciona la opción de guardar.

## Complejidad

Las principales operaciones del programa tienen estas complejidades:

* Cargar mascotas: **O(n)**
* Mostrar mascotas: **O(n)**
* Guardar mascotas: **O(n)**
* Ordenar con Merge Sort: **O(n log n)**
* Obtener un dato de una mascota: **O(1)**

Merge Sort utiliza **O(n)** de espacio extra debido a los vectores temporales que utiliza durante el ordenamiento.


## Autor

Gabriela Estrada Guerrero


## Cómo compilar y ejecutar
```bash
g++ -std=c++17 -o programa main.cpp mascota.cpp ordenamiento.cpp
./programa
```

