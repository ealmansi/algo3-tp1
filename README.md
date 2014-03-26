# Algoritmos y Estructuras de Datos 3
## Trabajo Práctico 1 - Primer cuatrimestre de 2014

### Compilación
> make
>
> make informe

Desde el directorio raíz. Genera los ejecutables problema1, problema2, problema3 y medir_performance en la carpeta ./bin.

### Tests de verificación
> ./tests/correr_tests.sh "<"problema1 | problema2 | problema3">"

Para correr los tests de verificación de un problema. Se leen de la carpeta ./tests/"<"problema">".

### Mediciones de performance
> ./mediciones/tomar_mediciones.sh "<"problema1 | problema2 | problema3">" "<"max_n">"

Para generar archivos de datos con mediciones para instancias de peor caso, mejor caso y aleatorias, de tamaños 1 hasta max_n. Se guardan en ./mediciones/"<"problema">".