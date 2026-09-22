# sistema-adopciones
# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio

## Problema que resuelve
Un refugio de animales necesita gestionar su lista de mascotas disponibles y
poder consultarlas ordenadas por distintos criterios (nombre, edad, especie,
raza) para atender más rápido a las personas que buscan adoptar. El programa
carga los datos desde un archivo CSV, permite ordenarlos bajo demanda y
guarda el resultado en disco.

## Estructuras de datos utilizadas
- **Clase `Mascota`**: encapsula los atributos de cada registro (id, nombre,
  especie, raza, edad, tamaño) con getters y un método `mostrar()`.
  Complejidad de cualquier getter: **O(1)**.
- **`std::vector<Mascota>`**: contenedor dinámico usado para almacenar todas
  las mascotas cargadas del archivo. Se eligió sobre una lista enlazada
  porque el programa necesita acceso indexado O(1) (indispensable para
  Merge Sort, que divide por índices) y porque el tamaño del dataset es
  conocido/moderado, por lo que el costo de un posible *resize* interno es
  amortizado O(1) y no afecta el rendimiento general.

## Algoritmo de ordenamiento: Merge Sort
Se implementó **Merge Sort** de forma independiente para cada criterio
(nombre, edad, especie, raza) en `ordenamiento.cpp`.

**¿Por qué Merge Sort y no otro algoritmo?**
- Garantiza **O(n log n)** en el peor caso, a diferencia de algoritmos como
  Quick Sort (O(n²) en el peor caso) o Bubble/Insertion Sort (O(n²) siempre).
- Es **estable**: si dos mascotas tienen el mismo valor en el criterio de
  orden (ej. dos con la misma edad), conservan su orden relativo original.
  Esto es deseable en un catálogo real, donde no se quiere "revolver"
  registros que ya coincidían.
- El dataset se recarga o reordena con frecuencia (cada vez que el usuario
  cambia de criterio), por lo que un algoritmo con complejidad garantizada
  y predecible es preferible a uno con mejor caso promedio pero peor caso
  inestable.

## Análisis de complejidad

### Merge Sort (para cualquiera de los 4 criterios)
- **Tiempo:** cada llamada recursiva divide el arreglo en dos mitades →
  `T(n) = 2T(n/2) + O(n)` (el `O(n)` es el costo de `merge`, que recorre
  ambas mitades una vez). Por el teorema maestro, esto da:
  - Mejor caso: **O(n log n)**
  - Caso promedio: **O(n log n)**
  - Peor caso: **O(n log n)**
- **Espacio:** `merge` crea vectores temporales `izquierda` y `derecha` en
  cada llamada → **O(n)** espacio auxiliar (más O(log n) de la pila de
  recursión).
- Como hay 4 versiones (una por campo), cada una tiene la misma complejidad;
  el usuario solo ejecuta **una** por operación, así que el costo de una
  sola invocación del programa (elegir un criterio y ordenar) es O(n log n),
  no 4·O(n log n).

### Lectura de archivo (`cargarMascotas`)
Recorre cada línea del CSV una vez y hace `push_back` por cada una:
**O(n)** en tiempo, **O(n)** en espacio (el vector resultante).

### Escritura de archivo (`guardarMascotas`)
Recorre el vector una vez y escribe cada línea: **O(n)** en tiempo.

### Acceso/consulta (`mostrarTodas`, getters)
Recorrer y mostrar todas las mascotas es **O(n)**; acceder a un atributo de
una mascota puntual es **O(1)**.

### Complejidad total del programa
Por cada ciclo del menú (cargar → ordenar → mostrar/guardar), el costo
dominante es el ordenamiento: **O(n log n) en tiempo, O(n) en espacio**,
ya que O(n) (lectura), O(n) (escritura) y O(n) (mostrar) quedan absorbidos
por el término O(n log n).

## Mecanismos implementados
- **Lectura:** `cargarMascotas()` parsea `mascotas.csv` línea por línea con
  `stringstream` y construye el vector de objetos `Mascota`.
- **Escritura:** `guardarMascotas()` vuelca el vector (ya ordenado) a
  `mascotas_ordenado.csv`, para no perder el trabajo de ordenar al cerrar
  el programa.
- **Consulta:** el menú permite ordenar y mostrar por Nombre, Edad, Especie
  o Raza, y recargar el archivo original sin reiniciar el programa.

## Cómo compilar y ejecutar
```bash
g++ -std=c++17 -o programa main.cpp mascota.cpp ordenamiento.cpp
./programa
```
El archivo `mascotas.csv` debe estar en la misma carpeta que el ejecutable.

