# Algoritmos y Estructuras de Datos 3
## Trabajo Práctico 1 - Primer cuatrimestre de 2014

### Problemas

Por cada problema hay un archivo ./src/&lt;problema&gt;/&lt;problema&gt;_impl.cpp donde se definen las funciones: 

- leer_entrada
- escribir_salida
- resolver
- generar_instancia_xxxxx (varias)

Las funciones generar_instancia_xxxxx reciben un parámetro n y generan una instancia de tamaño n para realizar mediciones de tiempo de ejecución vs tamaño de instancia automáticamente.

### Compilación
> make
>
> make informe

Se ejecutan estos comandos desde el directorio raíz. Genera los ejecutables problema1, problema2, problema3 y medir_performance en la carpeta ./bin.

### Tests de verificación
> ./tests/correr_tests.sh &lt;problema1 | problema2 | problema3&gt;

Para correr los tests de verificación de un problema. Se leen las entradas de test de la carpeta ./tests/&lt;problema&gt; (archivos nombre.in), y se compara la salida con los archivos nombre.out.

### Mediciones de performance
> ./mediciones/tomar_mediciones.sh &lt;problema1 | problema2 | problema3&gt; &lt;max_n&gt;

Para generar archivos de datos con mediciones para instancias generadas dinamicamente (todas las definidas por las funciones generar_instancia_xxxxx de cada problema), de tamaños 1 hasta max_n. Se guardan en ./mediciones/&lt;problema&gt;.