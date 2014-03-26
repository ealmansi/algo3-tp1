#include <iostream>
#include <vector>
#include <algorithm>

#include "problema3.h"

using namespace std;
using namespace Problema3;

bool Problema3::leer_entrada(Entrada& e)
{
  cin >> e.n;
  if(!cin) return false;

  cin >> e.m;
  cin >> e.c;

  for (int i = 0; i < e.n * e.m; ++i)
  {
    int sup, izq, der, inf;
    cin >> sup;
    cin >> izq;
    cin >> der;
    cin >> inf;
    e.piezas.push_back(Entrada::Pieza(i+1, sup, izq, der, inf));
  }

  return true;
}

void Problema3::escribir_salida(Salida& s)
{
  for (vector<vector<int> >::const_iterator i = s.casillas.begin(); i != s.casillas.end(); ++i)
  {
    for (vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
      cout << *j  << " ";
    cout << endl;
  }
}

Salida Problema3::resolver(const Entrada& e)
{
  Salida s = {.casillas = vector<vector<int> >()};
  return s;
}

Entrada Problema3::generar_instancia_unidimensional(int n)
{
  Entrada e;
  
  e.n = n;
  e.m = 1;
  e.c = 10;
  for (int i = 0; i < n * 1; ++i)
    e.piezas.push_back(Entrada::Pieza(i+1, i*2 % e.c, i*3 % e.c, i*5 % e.c, i*7 % e.c));
  
  return e;
}

Entrada Problema3::generar_instancia_cuadrada(int n)
{
  Entrada e;
  
  e.n = n;
  e.m = n;
  e.c = 10;
  for (int i = 0; i < n * n; ++i)
    e.piezas.push_back(Entrada::Pieza(i+1, i*2 % e.c, i*3 % e.c, i*5 % e.c, i*7 % e.c));
  
  return e;
}