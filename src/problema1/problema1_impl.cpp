#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

#include "problema1.h"

using namespace std;
using namespace Problema1;

bool Problema1::leer_entrada(Entrada &e)
{
  cin >> e.cant_dias_inspeccion;
  if (e.cant_dias_inspeccion == 0) return false;

  cin >> e.cant_dias;
  for (int i = 0; i < e.cant_dias; ++i)
  {
    int dia;
    cin >> dia;
    e.dias.push_back(dia);
  }

  return true;
}

void Problema1::escribir_salida(Salida &s)
{
  cout << s.dia_inicial << " " << s.max_cant_camiones << endl;
}

Salida Problema1::resolver(const Entrada &e)
{
  Salida s;

  vector<int> dias(e.dias);
  sort(dias.begin(), dias.end());

  s.dia_inicial = -1;
  s.max_cant_camiones = -1;
  int i = 0, j = 0, cant_camiones;
  for (; i < e.cant_dias; ++i)
  {
    if (0 < i && dias[i - 1] == dias[i]) continue;
	
    for (; (j < e.cant_dias) && (dias[j] - dias[i] < e.cant_dias_inspeccion); ++j)
      /* vacío */;

    cant_camiones = j - i;
    if (s.max_cant_camiones < cant_camiones)
    {
      s.max_cant_camiones = cant_camiones;
      s.dia_inicial = dias[i];
    }
  }

  return s;
}

Entrada Problema1::generar_instancia_aleatoria(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = rand();
  e.cant_dias = n;
  for (int i = 0; i < n; ++i)
    e.dias.push_back(rand());

  return e;
}

Entrada Problema1::generar_instancia_ordenada_aleatoria(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = rand();
  e.cant_dias = n;
  for (int i = 0; i < n; ++i)
    e.dias.push_back(rand());

  sort(e.dias.begin(), e.dias.end());

  return e;
}

Entrada Problema1::generar_instancia_ordenada_siempre_actualiza(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = 1;
  e.cant_dias = n;
  int elem = 1, aux = 1;
  for (int i = 1; i <= n; ++i) {
    e.dias.push_back(elem);
    if (i == aux) { 
      ++elem;
      aux = aux + elem;
    }
  }

  return e;
}

Entrada Problema1::generar_instancia_ordenada_todos_distintos(int n)
{
  Entrada e;

  e.cant_dias_inspeccion = 1;
  e.cant_dias = n;
  for (int i = 0; i < n; ++i)
    e.dias.push_back(i+1);

  return e;
}
