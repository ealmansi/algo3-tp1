#include <iostream>
#include <vector>
#include <algorithm>

#include "problema1.h"

using namespace std;
using namespace Problema1;

bool Problema1::leer_entrada(Entrada& e)
{
  cin >> e.cant_dias_inspeccion;
  if(e.cant_dias_inspeccion == 0) return false;

  cin >> e.cant_dias;
  for (int i = 0; i < e.cant_dias; ++i)
  {
    int dia;
    cin >> dia;
    e.dias.push_back(dia);
  }

  return true;
}

void Problema1::escribir_salida(Salida& s)
{
  cout << s.dia_inicial << " " << s.max_cant_camiones << endl;
}

Salida Problema1::resolver(const Entrada& e)
{
  Salida s;

  vector<int> dias(e.dias);
  sort(dias.begin(), dias.end());
  
  s.dia_inicial = -1;
  s.max_cant_camiones = -1;
  int i = 0, j = 0, cant_camiones;
  for (; i < e.cant_dias; ++i)
  {
    for (; (j < e.cant_dias) && (dias[j] - dias[i] < e.cant_dias_inspeccion); ++j)
      ;
    cant_camiones = j - i;
    if(s.max_cant_camiones < cant_camiones)
    {
      s.max_cant_camiones = cant_camiones;
      s.dia_inicial = dias[i];
    }
  }

  return s;
}

Entrada Problema1::generar_instancia_mejor_caso(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = 10;
  e.cant_dias = n;
  for (int i = 0; i < n; ++i)
    e.dias.push_back(i);
  
  return e;
}

Entrada Problema1::generar_instancia_peor_caso(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = 10;
  e.cant_dias = n;
  for (int i = 0; i < n; ++i)
    e.dias.push_back(i);
  
  return e;
}

Entrada Problema1::generar_instancia_aleatoria(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = 10;
  e.cant_dias = n;
  for (int i = 0; i < n; ++i)
    e.dias.push_back(i);
  
  return e;
}