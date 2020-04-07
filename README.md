# Tarea *3*. *Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *Sergio Hernandez Castillo* - *A01025210* - *CSF*
---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

*A continuación se presentan los planteamientos de los dos problemas, así como las soluciones implementadas:*

*Problema 1:*

*Supongamos que disponemos de n trabajadores y n tareas. Sea bij > 0 el coste de asignarle el trabajo j al trabajador i. Una asignación de tareas puede ser expresada como una asignación de los valores 0 ó 1 a las variables xij, donde xij = 0 significa que al trabajador i no le han asignado la tarea j, y xij = 1 indica que sí. Una asignación válida es aquella en la que a cada trabajador sólo le corresponde una tarea y cada tarea está asignada a un trabajador. Dada una asignación válida, definimos el coste de dicha asignación como: ∑n ∑n xijbij, i=1 j=1. Diremos que una asignación es óptima si es de mínimo coste.*

*Este problema requiere resolverse utilizando un algoritmo ávido. Lo que se hizo para resolverlo de esa manera fue lo siguiente:*

*1) Se le preguntó al usuario cuantas tareas hay en esta ocasión, tomando en cuenta que el número de trabajadores es igual.*

*2) Se le preguntó al usuario cual es el máximo costo que existe para una tarea.*

*3) Se creó un vector de 2 dimensiones que representará los costos de las tareas por trabajador. Este vector ocupa la cantidad de tareas como el tamaño, es decir, si el numero de tareas es "n", el tamaño del vector será "[n][n]"*

*4) Se creó un vector de 2 dimensiones que representará la asignación de tareas. El tamaño de este vector es igual que el anterior y una asignación se representa como un 1, mientras que un 0 significa que la tarea no fue asignada.*

*5) Se llenó el vector de costos con números aleatorios entre 1 y el máximo costo.*

*6) La asignación de tareas empieza. Utilizando dos ciclos "for", uno dentro de otro, se iteró sobre el vector de costos, columna por columna, y dentro de cada columna, fila por fila. En otras palabras, se analizaron los costos que cada trabajador tiene por tarea. Primero, se revisa si un trabajador está libre antes de analizar si su costo es óptimo. Si ese es el caso y su costo es el más óptimo de los "n" trabajadores (el más chico), su posición en el vector de costos se guarda. Si el trabajador no estaba libre, se analiza el siguiente trabajador. Si hubo otro trabajador con un mejor costo, se descarta el anterior y la posición del actual se guarda, si no, entonces el anterior se mantiene guardado. Al haber acabado iterando sobre los "n" trabajadores, se asigna la tarea al trabajador con el costo óptimo (se guarda un 1 en su posición en el vector de asignaciones) y se analiza la siguiente tarea/columna, hasta acabar con todas.*

*7) El costo total de la solución obtenida es calculada.*

*8) La solución se imprime para el usuario (que trabajador fue asignado a que tarea y cuanto es el costo total)*

*Problema 2:*

*Sea W un conjunto de enteros no negativos y M un número entero positivo. El problema consiste en diseñar un algoritmo para encontrar todos los posibles subconjuntos de W cuya suma sea exactamente M.*

*Este problema requiere resolverse utilizando la técnica de diseño de algoritmos conocida como Backtracking/Vuelta atras. Lo que se hizo para resolverlo de esa manera fue lo siguiente:*

*1) Se le preguntó al usuario el tamaño del conjunto de enteros no negativos, asegurando que el tamaño no sea menor o igual a 0.*

*2) Se creó un arreglo del tamaño del conjunto.*

*3) Se creó un vector vació que guardará todos los subconjuntos que sumarán al entero objetivo, si es que existen.*

*4) Se le preguntó al usuario cuales enteros deseaba analizar/agregar al conjunto y se agregan al arreglo, asegurándo que los números dados no se repitan y que no sean menor o igual a 0.*

*5) Se le preguntó al usuario el entero objetivo, asegurándo que no sea menor o igual a 0.*

*6) El algoritmo empieza a buscar subconjuntos, cuyas sumas sean igual al entero positivo, dentro del conjunto. Hace esto utilizando recursión, junto con un grupo extra de variables para ayudar. Se toma en cuenta la posición del arreglo como la raíz de la solución y una suma que será analizada cada vez que el algoritmo se llama a sí mismo. Ambas variables empiezan en 0. Primero, se analiza si la suma es igual al entero objetivo, si no lo es, un ciclo "for" itera sobre el arreglo/conjunto, partiendo desde la posición dada. Segundo, dentro del ciclo, si lo que vale suma más el elemento siendo analizado es menor o igual al entero objetivo, la suma se guarda como sí misma más el elemento siendo analizado, se guarda el elemento en el vector de soluciones, y el algoritmo se llama a sí mismo, pero ahora con el nuevo valor de la suma y la posición incrementada por uno. El mismo proceso va a seguir corriendo una y otra vez hasta que la suma sea igual al entero objetivo. Si ese es el caso, el vector de soluciones se imprime para el usuario. Ahora, después de que una llamada recursiva acabe de correr, la suma y el vector de soluciones regresan al estado/valor que tenían antes de hacer la llamada recursiva, para asegurar que otros subconjuntos sean encontrados y impresos para el usuario.*

### 2.1 Pasos a seguir para utilizar la aplicación

*[Incluya aquí una guía paso a paso para poder utilizar la aplicación, desde la clonación del repositorio, la compilación del código hasta la ejecución de los ejemplos para visualizar los resultados.]*

## 3. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar la actividad y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
