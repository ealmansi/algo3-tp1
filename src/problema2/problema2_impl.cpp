#include <iostream>
#include <vector>
#include <algorithm>

#include "problema2.h"

using namespace std;
using namespace Problema2;

bool Problema2::leer_entrada(Entrada &e)
{
  cin >> e.cant_piezas;
  if (e.cant_piezas == 0) return false;

  for (int i = 0; i < e.cant_piezas; ++i)
  {
    int di, ti;
    cin >> di;
    cin >> ti;
    e.piezas.push_back(Pieza(i + 1, di, ti));
  }

  return true;
}

void Problema2::escribir_salida(Salida &s)
{
  for (vector<Pieza>::const_iterator i = s.piezas.begin(); i != s.piezas.end(); ++i)
    cout << i->indice << " ";
  cout << s.perdida_total << endl;
}

Salida Problema2::resolver(const Entrada &e)
{
  Salida s; 
  s.piezas = vector<Pieza>(e.piezas);
  s.perdida_total = 0;

  sort(s.piezas.begin(), s.piezas.end(), Pieza::comparar_piezas);

  int acum_tiempo = 0;
  for (vector<Pieza>::const_iterator i = s.piezas.begin(); i != s.piezas.end(); ++i)
  {
    acum_tiempo += i->tiempo;
    s.perdida_total += acum_tiempo * i->perdida;
  }

  return s;
}

Entrada Problema2::generar_instancia_mejor_caso(int n)
{
  Entrada e;

  e.cant_piezas = n;
  for (int i = 0; i < n; ++i)
    e.piezas.push_back(Pieza(i + 1, i, i));

  return e;
}

Entrada Problema2::generar_instancia_peor_caso(int n)
{
  Entrada e;

  e.cant_piezas = n;
  for (int i = 0; i < n; ++i)
    e.piezas.push_back(Pieza(i + 1, i, i));

  return e;
}

Entrada Problema2::generar_instancia_aleatoria(int n)
{
  Entrada e;

  e.cant_piezas = n;
  for (int i = 0; i < n; ++i)
    e.piezas.push_back(Pieza(i + 1, i, i));

  return e;
}
