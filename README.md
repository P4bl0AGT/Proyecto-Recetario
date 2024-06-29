# Gestor de Recetas

## Descripción del Programa
El Gestor de Recetas es una aplicación diseñada para facilitar la gestión de recetas de cocina. Este programa permite a los usuarios crear, modificar, eliminar y consultar recetas, proporcionando una solución integral para organizar y acceder a recetas de manera eficiente.

### Características Principales
1. **Agregar Recetas:** Permite a los usuarios ingresar nuevas recetas incluyendo el nombre de la receta, la categoría a la que pertenece, los ingredientes necesarios y las instrucciones detalladas para su preparación.
2. **Mostrar Recetas por Nombre:** Lista todas las recetas almacenadas mostrando únicamente sus nombres para una navegación rápida.
3. **Mostrar Recetas por Categoría:** Agrupa y muestra las recetas según la categoría a la que pertenecen, facilitando la búsqueda por tipo de plato.
4. **Consultar Recetas:** Permite buscar y visualizar recetas específicas por su nombre, mostrando todos los detalles asociados a la receta.
5. **Modificar Recetas:** Facilita la actualización de recetas existentes, permitiendo cambios en el nombre, la categoría, los ingredientes y las instrucciones.
6. **Eliminar Recetas:** Ofrece la opción de eliminar recetas que ya no sean necesarias o que se deseen retirar del sistema.
7. **Salir:** Ofrece la opcion de salir del programa y guarda las recetas en el archivo del recetario.
8. **Guardar Recetas:** Almacena todas las recetas en un archivo, asegurando que la información se mantenga disponible para futuras sesiones.
9. **Cargar Recetas:** Carga las recetas desde un archivo al iniciar el programa, permitiendo la continuación del trabajo previo sin pérdida de información.

### Beneficios del Uso
- **Organización Eficiente:** Mantén todas tus recetas organizadas en un solo lugar, categorizadas y fácilmente accesibles.
- **Facilidad de Uso:** Interfaz sencilla que permite agregar y consultar recetas de manera intuitiva.
- **Flexibilidad:** Modifica y actualiza recetas según tus necesidades y gustos.
- **Portabilidad:** Guarda y carga recetas desde archivos, facilitando el respaldo y la transferencia de datos.

## Como compilar y ejecutar
Dado que el sistema está diseñado para ser accesible y fácil de probar, recomendamos usar [Repl.it](http://repl.it/) para una rápida configuración y ejecución. Sigue estos pasos para comenzar:

1. Visita [Repl.it](https://repl.it/).
2. Crea una nueva cuenta o inicia sesión si ya tienes una.
3. Una vez en tu dashboard, selecciona "New Repl" y elige "Import from GitHub".
4. Pega la URL del repositorio: `https://github.com/P4bl0AGT/8-puzzle`.
5. [Repl.it](http://repl.it/) clonará el repositorio y preparará un entorno de ejecución.
6. Presiona el botón "Run" para compilar y ejecutar la aplicación.

## Funcionalidades

### Funcionando correctamente:
* **Agregar Recetas:** Permite agregar nuevas recetas ingresando el nombre, la categoría, los ingredientes y las instrucciones.
* **Mostrar Recetas por Nombre:** Lista todas las recetas almacenadas mostrando sus nombres.
* **Mostrar Recetas por Categoría:** Lista todas las recetas organizadas por categoría.
* **Consultar Recetas:** Permite consultar una receta específica por su nombre, mostrando todos los detalles.
* **Modificar Recetas:** Permite modificar los detalles de una receta existente.
* **Eliminar Recetas:** Permite eliminar una receta específica del sistema.
* **Guardar Recetas:** Guarda todas las recetas en un archivo para su posterior recuperación.
* **Cargar Recetas:** Carga las recetas desde un archivo al iniciar el programa.

### Problemas conocidos:
* **Problemas de espacio:** Con algunos ingredientes o instrucciones muy largas.
* **Límite de memoria:** Dependiendo de la plataforma, especialmente en entornos limitados como Repl.it, puede haber problemas de memoria al manejar muchas recetas.

### A mejorar:
* **Gestión de Memoria:** Mejorar la gestión de memoria para evitar problemas de espacio.
* **Búsqueda Avanzada:** Implementar funciones de búsqueda avanzada y filtrado de recetas.

## Ejemplo de uso

### Agregar una receta:
1. Selecciona la opción para agregar una receta en el menú principal.
   ```bash
   =====================================
                 Recetario
   =====================================
   (1) Ingresar Receta
   (2) Mostrar Recetas Por Nombres
   (3) Mostrar Recetas Por Categorias
   (4) Consultar Receta
   (5) Modificar Receta
   (6) Eliminar Receta
   (7) Salir
   Ingrese una opcion: 1
   ```
3. Ingresa el nombre de la receta:
    ```bash
    | ----------  Agregar Receta ---------- |
    Ingrese el nombre de su receta: Ensalada
    ```
4. Ingresa la categoría de la receta:
    ```bash
    Ingrese la categoria de su receta: Entrada
    ```
5. Agrega los ingredientes uno por uno:
    ```bash
    | ----------- Ingredientes ----------- |
    Si no quiere ingresar mas ingredientes, ingrese FIN
    Ingrese su ingrediente: Lechuga
    Ingrese la cantidad del ingrediente: 1
    1 de Lechuga

    Ingrese su ingrediente: Tomate
    Ingrese la cantidad del ingrediente: 2
    2 de Tomate

    Ingrese su ingrediente: FIN
    ```
6. Agrega las instrucciones una por una:
    ```bash
    | ---------- Instrucciones ---------- |
    Si no quiere ingresar mas instrucciones, ingrese FIN
    Ingrese su instruccion: Lavar la lechuga
    Paso 1 instruccion: Lavar la lechuga

    Ingrese su instruccion: Cortar el tomate
    Paso 2 instruccion: Cortar el tomate

    Ingrese su instruccion: Mezclar los ingredientes 
    Paso 3 instruccion: Mezclar los ingredientes 

    Ingrese su instruccion: FIN
    RECETA GUARDADA EXITOSAMENTE
    ```

### Mostrar todas las recetas por nombre:
1. Selecciona la opción para mostrar todas las recetas por nombre en el menú principal.
   ```bash
      =====================================
                    Recetario
      =====================================
      (1) Ingresar Receta
      (2) Mostrar Recetas Por Nombres
      (3) Mostrar Recetas Por Categorias
      (4) Consultar Receta
      (5) Modificar Receta
      (6) Eliminar Receta
      (7) Salir
      Ingrese una opcion: 2
      ```
3. Visualiza la lista de nombres de recetas:
    ```bash
    | ---------- Mostrar Recetas ---------- |
    - Ensalada
    - Sopa de Verduras
    ```

### Mostrar todas las recetas por categoría:
1. Selecciona la opción para mostrar todas las recetas por categoría en el menú principal.
   ```bash
      =====================================
                    Recetario
      =====================================
      (1) Ingresar Receta
      (2) Mostrar Recetas Por Nombres
      (3) Mostrar Recetas Por Categorias
      (4) Consultar Receta
      (5) Modificar Receta
      (6) Eliminar Receta
      (7) Salir
      Ingrese una opcion: 3
      ```
3. Visualiza la lista de recetas organizadas por categoría:
    ```bash
    | ---------- Mostrar Recetas por Categorias ---------- |
    Categoria: Entrada
    - Ensalada
    Categoria: Plato Principal
    - Sopa de Verduras
    ```

### Consultar una receta:
1. Selecciona la opción para consultar una receta en el menú principal.
   ```bash
      =====================================
                    Recetario
      =====================================
      (1) Ingresar Receta
      (2) Mostrar Recetas Por Nombres
      (3) Mostrar Recetas Por Categorias
      (4) Consultar Receta
      (5) Modificar Receta
      (6) Eliminar Receta
      (7) Salir
      Ingrese una opcion: 4
      ```
3. Ingresa el nombre de la receta que deseas consultar:
    ```bash
    Ingrese el nombre de la receta: Ensalada
    ```
4. Visualiza los detalles de la receta:
    ```bash
    | ---------- Revisar Receta ---------- |
    Ingrese el nombre de la receta: Ensalada
    | ---------- Datos Receta ---------- |
     Nombre de la receta: Ensalada
     Categoria de la receta: Entrada
    | ---------- Ingredientes ---------- |
    1 de Lechuga
    2 de Tomate
    | ---------- Instrucciones ---------- |
    1) Lavar la lechuga
    2) Cortar el tomate
    3) Mezclar los ingredientes
    ```

### Modificar una receta:
1. Selecciona la opción para modificar una receta en el menú principal.
   ```bash
      =====================================
                    Recetario
      =====================================
      (1) Ingresar Receta
      (2) Mostrar Recetas Por Nombres
      (3) Mostrar Recetas Por Categorias
      (4) Consultar Receta
      (5) Modificar Receta
      (6) Eliminar Receta
      (7) Salir
      Ingrese una opcion: 5
      ```
3. Ingresa el nombre de la receta que deseas modificar:
    ```bash
    Ingrese el nombre de la receta: Ensalada
    ```
4. Modifica los detalles de la receta según se solicite:
    ```bash
    | ---------- Modificar Receta ---------- |
     Ingrese el nombre de la receta: Ensalada
    | ---------- NOMBRE ---------- |
     Desea modificar el nombre de la receta? (s/n) :n
    | ---------- CATEGORIA ---------- |
     Desea modificar la categoria de la receta? (s/n) :s
     Ingrese la nueva categoria de la receta: Cena
    | ---------- INGREDIENTES ---------- |
     Desea modificar los ingredientes de la receta? (s/n) :n
    | ---------- INGREDIENTES ---------- |
     Desea modificar las instrucciones de la receta? (s/n) :n
     LA RECETA SE MODIFICO CORRECTAMENTE
    ```

### Eliminar una receta:
1. Selecciona la opción para eliminar una receta en el menú principal.
   ```bash
      =====================================
                    Recetario
      =====================================
      (1) Ingresar Receta
      (2) Mostrar Recetas Por Nombres
      (3) Mostrar Recetas Por Categorias
      (4) Consultar Receta
      (5) Modificar Receta
      (6) Eliminar Receta
      (7) Salir
      Ingrese una opcion: 6
      ```
3. Ingresa el nombre de la receta que deseas eliminar:
    ```bash
    | ---------- Eliminar Receta ---------- |
    Ingrese el nombre de la receta: Ensalada
    ```
5. Confirma que la receta ha sido eliminada:
    ```bash
    LA RECETA Ensalada SE ELIMINO CORRECTAMENTE
    ```
### Salir:
1. Seleccion la opcion para salir del programa
   ```bash
      =====================================
                    Recetario
      =====================================
      (1) Ingresar Receta
      (2) Mostrar Recetas Por Nombres
      (3) Mostrar Recetas Por Categorias
      (4) Consultar Receta
      (5) Modificar Receta
      (6) Eliminar Receta
      (7) Salir
      Ingrese una opcion: 7
      ```
2. Se termina la ejecucíon del programa.

## Contribuciones del codigo
Cada integrante del equipo ha contribuido de la siguiente manera:

- **Pablo Aguilera Tapia:** Se encargo de realizar las funciones de agregar, modificar , consultar ademas de plantear las estructuras y documentar el codigo, todo lo demas fue entre ambos.
- **Benjamin Gomez Beltran:** Se encargo de realizar las funciones de mostrar nombres, categorias asi como las funciones extras de guardar y cargar las recetas y documentar el codigo, todo lo demas fue entre ambos.
