#include <iostream>
#include <vector>
#include <algorithm>

#include "problema1.h"

using namespace std;
using namespace Problema1;

bool Problema1::leer_entrada(Entrada& e)
{
  int& cant_dias_inspeccion = e.D;
  int& cant_dias = e.n;
  vector<int>& dias = e.d;

  cin >> cant_dias_inspeccion;
  if(cant_dias_inspeccion == 0) return false;

  cin >> cant_dias;
  for (int i = 0; i < cant_dias; ++i)
  {
    int dia;
    cin >> dia;
    dias.push_back(dia);
  }

  return true;
}

void Problema1::escribir_salida(Salida& s)
{
  int& dia_inicial = s.d;
  int& cant_camiones = s.c;

  cout << dia_inicial << " " << cant_camiones << endl;
}

Salida Problema1::resolver(Entrada& e)
{
  int& cant_dias_inspeccion = e.D;
  int& cant_dias = e.n;
  vector<int>& dias = e.d;

  int dia_inicial = -1;
  int max_cant_camiones = -1;
  int i, j, cant_camiones;

  sort(dias.begin(), dias.end());
  
  i = j = 0;
  for (; i < cant_dias; ++i)
  {
    for (; (j < cant_dias) && (dias[j] - dias[i] < cant_dias_inspeccion); ++j)
      ;
    cant_camiones = j - i;
    if(max_cant_camiones < cant_camiones)
    {
      max_cant_camiones = cant_camiones;
      dia_inicial = dias[i];
    }
  }

  Salida s = {.d = dia_inicial, .c = max_cant_camiones};
  return s;
}

Entrada Problema1::generar_instancia_mejor_caso(int n)
{
  Entrada e;
  e.D = 10;
  e.n = n;
  for (int i = 0; i < n; ++i)
    e.d.push_back(i);
  
  return e;
}

Entrada Problema1::generar_instancia_peor_caso(int n)
{
  Entrada e;
  e.D = 10;
  e.n = n;
  for (int i = 0; i < n; ++i)
    e.d.push_back(i);
  
  return e;
}

Entrada Problema1::generar_instancia_aleatoria(int n)
{
  Entrada e;
  e.D = 10;
  e.n = n;
  for (int i = 0; i < n; ++i)
    e.d.push_back(i);
  
  return e;
}