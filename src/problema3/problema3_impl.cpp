#include <iostream>
#include <vector>
#include <algorithm>

#include "problema3.h"

using namespace std;
using namespace Problema3;

bool Problema3::leer_entrada(Entrada& e)
{
  int& n = e.n, m = e.m, c = e.c;
  vector<Entrada::Pieza>& piezas = e.piezas;

  if(cin.eof()) return false;

  cin >> n;
  cin >> m;
  cin >> c;

  for (int i = 0; i < n * m; ++i)
  {
    int sup, izq, der, inf;
    cin >> sup;
    cin >> izq;
    cin >> der;
    cin >> inf;
    piezas.push_back(Entrada::Pieza(i+1, sup, izq, der, inf));
  }

  return true;
}

void Problema3::escribir_salida(Salida& s)
{
  vector<vector<int> >& casillas = s.casillas;

  for (vector<vector<int> >::const_iterator fila = casillas.begin(); fila != casillas.end(); ++fila)
  {
    for (vector<int>::const_iterator i = fila->begin(); i != fila->end(); ++i)
      cout << *i  << " ";
    cout << endl;
  }
}

Salida Problema3::resolver(Entrada& e)
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