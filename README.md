# sistema-adopciones
# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio

# Sistema de Adopciones

## Descripción

Este proyecto es un programa en C++ que sirve para organizar información de mascotas de un refugio.

El programa guarda los datos de las mascotas en un archivo y permite mostrarlos y ordenarlos de diferentes maneras.

## Problema

Un refugio puede tener información de varias mascotas y puede ser difícil organizarla cuando hay muchos datos.

Por eso, el programa permite guardar la información de las mascotas en un solo archivo y ordenarla por diferentes características para que sea más fácil consultarla.

## Datos de las mascotas

Cada mascota tiene los siguientes datos:

* ID
* Nombre
* Especie
* Raza
* Edad
* Tamaño

## ¿Qué puede hacer el programa?

El programa tiene un menú principal con las siguientes opciones:

1. Mostrar mascotas.
2. Ordenar mascotas.
3. Guardar mascotas.
4. Salir.

Al elegir la opción de ordenar, se puede ordenar la información por:

* Nombre
* Edad
* Especie
* Raza

## Estructura de datos

Para guardar las mascotas se utiliza un `vector<Mascota>`.

Se eligió un `vector` porque permite guardar varias mascotas y acceder a ellas mediante sus posiciones.

También se creó una clase llamada `Mascota`, donde se guardan los datos de cada mascota.

## Ordenamiento

Para ordenar las mascotas se utilizó **Merge Sort**.

Se eligió este algoritmo porque es uno de los algoritmos de ordenamiento que vimos en clase y porque funciona bien para ordenar una cantidad de datos que puede ir aumentando.

Otra razón es que Merge Sort tiene una complejidad de **O(n log n)** en el mejor, promedio y peor caso, por lo que mantiene un buen rendimiento aunque aumente la cantidad de mascotas.

Además, utiliza recursión. El algoritmo divide los datos en partes más pequeñas y después las vuelve a unir en el orden correcto.

En este proyecto se utiliza Merge Sort para ordenar las mascotas por nombre, edad, especie y raza.

El algoritmo utiliza **O(n)** de espacio extra porque necesita crear vectores temporales durante el ordenamiento.

## Lectura y escritura de archivos

Los datos de las mascotas se encuentran en el archivo:

```text
mascotas.txt
```

Al iniciar el programa, se leen los datos de este archivo utilizando `ifstream`.

También se puede guardar la información utilizando `ofstream`.

De esta manera, los datos de las mascotas no tienen que estar escritos directamente en el código.

## Complejidad

Las principales funciones del programa tienen las siguientes complejidades:

* Cargar mascotas: **O(n)**
* Mostrar mascotas: **O(n)**
* Guardar mascotas: **O(n)**
* Ordenar con Merge Sort: **O(n log n)**
* Obtener un dato de una mascota: **O(1)**

La complejidad de espacio de Merge Sort es **O(n)**.

## Archivos del proyecto

```text
sistema-adopciones/
│
├── main.cpp
├── mascota.h
├── mascota.cpp
├── ordenamiento.h
├── ordenamiento.cpp
└── mascotas.txt
```

### main.cpp

Contiene el menú principal y las funciones para cargar, mostrar y guardar las mascotas.

### mascota.h

Contiene la definición de la clase `Mascota`.

### mascota.cpp

Contiene la implementación de la clase `Mascota`.

### ordenamiento.h

Contiene las declaraciones de las funciones de Merge Sort.

### ordenamiento.cpp

Contiene la implementación de Merge Sort para los diferentes tipos de ordenamiento.

### mascotas.txt

Contiene los datos de las mascotas que utiliza el programa.

## Competencias

**SICT0301:** Se analiza la complejidad de Merge Sort y de las principales funciones del programa.

**SICT0302:** Se utiliza Merge Sort para ordenar las mascotas y un `vector` para guardar la información.

**SICT0303:** El programa puede leer y guardar información en un archivo utilizando `ifstream` y `ofstream`.

**SEG0701:** El programa busca facilitar la organización de información de mascotas mediante un menú sencillo.

## Cómo ejecutar el programa

Para compilar el programa se utiliza:

```bash
g++ main.cpp mascota.cpp ordenamiento.cpp -o adopciones
```

Para ejecutarlo:

```bash
./adopciones
```

Es necesario que el archivo `mascotas.txt` se encuentre en la misma carpeta que los archivos del programa.

## Tecnologías utilizadas

* C++
* Programación Orientada a Objetos
* `vector`
* `ifstream`
* `ofstream`
* `stringstream`
* Recursión
* Merge Sort
* Git y GitHub

## Autor

Gabriela Estrada Guerrero


## Cómo compilar y ejecutar
```bash
g++ -std=c++17 -o programa main.cpp mascota.cpp ordenamiento.cpp
./programa
```

