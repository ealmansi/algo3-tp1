#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>

#include "problema1/problema1.h"
#include "problema2/problema2.h"
#include "problema3/problema3.h"

using namespace std;

struct Medicion
{
  Medicion(int n, int tiempo) : n(n), tiempo(tiempo) {}
  int n;
  int tiempo;
};

/*    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    */

void imprimir_modo_de_uso();
vector<Medicion> tomar_mediciones(string& problema, string& funcion_generadora, int n_max);
void escribir_datos(vector<Medicion>& mediciones, string& nombre_archivo_salida);

/*    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    */

int main(int argc, char const *argv[])
{
  if(argc != 5)
  {
    imprimir_modo_de_uso();
    return 0;
  }

  string problema(argv[1]), funcion_generadora(argv[2]), nombre_archivo_salida(argv[4]);
  int n_max = atoi(argv[3]);

  try {
    vector<Medicion> mediciones = tomar_mediciones(problema, funcion_generadora, n_max);
    escribir_datos(mediciones, nombre_archivo_salida);
  } catch(const char* error) {
    cerr << error << endl;
  }

  return 0;
}

/*    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    *    */

void imprimir_modo_de_uso()
{
  cout << "Modo de uso: ./performance <problema> <funcion_generadora> <n_max> <nombre_archivo_salida>" << endl;
  cout << "Ejemplo:" << endl;
  cout << "\t./performance problema1 generar_instancia_mejor_caso 100 mediciones/p1_mejor_100.csv" << endl;
}

template <typename E, typename S>
vector<Medicion> tomar_mediciones(int n_max, E (*generar_instancia)(int), S (*resolver)(E&))
{
  vector<Medicion> mediciones;
  timespec inicio, fin;
  
  for (int n = 1; n <= n_max; ++n)
  {
    E e = generar_instancia(n);
    clock_gettime(CLOCK_REALTIME, &inicio);
    resolver(e);
    clock_gettime(CLOCK_REALTIME, &fin);
    mediciones.push_back(Medicion(n, (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec)));
  }
  
  return mediciones;
}

vector<Medicion> tomar_mediciones(string& problema, string& funcion_generadora, int n_max)
{
  if(n_max <= 0)
    throw "El argumento n_max es inválido.";

  if(problema == "problema1")
  { 
    if(funcion_generadora == "generar_instancia_mejor_caso") {
      return tomar_mediciones<Problema1::Entrada, Problema1::Salida>
        (n_max, Problema1::generar_instancia_mejor_caso, Problema1::resolver);
    } else if(funcion_generadora == "generar_instancia_peor_caso") {
      return tomar_mediciones<Problema1::Entrada, Problema1::Salida>
        (n_max, Problema1::generar_instancia_peor_caso, Problema1::resolver);
    } else if(funcion_generadora == "generar_instancia_aleatoria") {
      return tomar_mediciones<Problema1::Entrada, Problema1::Salida>
        (n_max, Problema1::generar_instancia_aleatoria, Problema1::resolver);
    } else {
      throw "El argumento funcion_generadora es inválido.";
    }
  } else if(problema == "problema2") { 
    if(funcion_generadora == "generar_instancia_mejor_caso") {
      return tomar_mediciones<Problema2::Entrada, Problema2::Salida>
        (n_max, Problema2::generar_instancia_mejor_caso, Problema2::resolver);
    } else if(funcion_generadora == "generar_instancia_peor_caso") {
      return tomar_mediciones<Problema2::Entrada, Problema2::Salida>
        (n_max, Problema2::generar_instancia_peor_caso, Problema2::resolver);
    } else if(funcion_generadora == "generar_instancia_aleatoria") {
      return tomar_mediciones<Problema2::Entrada, Problema2::Salida>
        (n_max, Problema2::generar_instancia_aleatoria, Problema2::resolver);
    } else {
      throw "El argumento funcion_generadora es inválido.";
    }
  // } else if(problema == "problema3") { 
  //   if(funcion_generadora == "generar_instancia_unidimensional") {
  //     return tomar_mediciones<Problema3::Entrada, Problema3::Salida>
  //       (n_max, Problema3::generar_instancia_unidimensional, Problema3::resolver);
  //   } else if(funcion_generadora == "generar_instancia_cuadrada") {
  //     return tomar_mediciones<Problema3::Entrada, Problema3::Salida>
  //       (n_max, Problema3::generar_instancia_cuadrada, Problema3::resolver);
  //   } else {
  //     throw "El argumento funcion_generadora es inválido.";
  //   }
  } else {
    throw "El argumento problema es inválido.";
  }
}

void escribir_datos(vector<Medicion>& mediciones, string& nombre_archivo_salida)
{
  ofstream archivo_salida;
  archivo_salida.open(nombre_archivo_salida.c_str());

  for (vector<Medicion>::const_iterator i = mediciones.begin(); i != mediciones.end(); ++i)
    archivo_salida << i->n << ";" << i->tiempo << ";" << endl;

  archivo_salida.close();
}