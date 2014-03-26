# Algoritmos y Estructuras de Datos 3
## Trabajo Práctico 1 - Primer cuatrimestre de 2014

### Compilación
> make
>
> make informe

Desde el directorio raíz. Genera los ejecutables problema1, problema2, problema3 y medir_performance en la carpeta ./bin.

### Tests de verificación
> ./tests/correr_tests.sh &lt;problema1 | problema2 | problema3&gt;

Para correr los tests de verificación de un problema. Se leen de la carpeta ./tests/&lt;problema&gt;.

### Mediciones de performance
> ./mediciones/tomar_mediciones.sh &lt;problema1 | problema2 | problema3&gt; &lt;max_n&gt;

Para generar archivos de datos con mediciones para instancias de peor caso, mejor caso y aleatorias, de tamaños 1 hasta max_n. Se guardan en ./mediciones/&lt;problema&gt;.