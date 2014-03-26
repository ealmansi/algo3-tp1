#include <iostream>
#include <vector>
#include <algorithm>

#include "problema2.h"

using namespace std;
using namespace Problema2;

bool Problema2::leer_entrada(Entrada& e)
{
  int& cant_piezas = e.n;
  vector<int>& perdidas = e.d;
  vector<int>& tiempos = e.t;

  cin >> cant_piezas;
  if(cant_piezas == 0) return false;

  for (int i = 0; i < cant_piezas; ++i)
  {
    int di, ti;
    cin >> di;
    cin >> ti;
    perdidas.push_back(di);
    tiempos.push_back(ti);
  }

  return true;
}

void Problema2::escribir_salida(Salida& s)
{
  vector<int>& indices = s.i;
  int& perdida_total = s.P;

  for (vector<int>::const_iterator i = indices.begin(); i != indices.end(); ++i)
    cout << *i << " ";
  cout << perdida_total << endl;
}

Salida Problema2::resolver(Entrada& e)
{
  int& cant_piezas = e.n;
  vector<int>& perdidas = e.d;
  vector<int>& tiempos = e.t;

  Salida s = {.i = perdidas, .P = cant_piezas + tiempos[0]};
  return s;
}

Entrada Problema2::generar_instancia_mejor_caso(int n)
{
  Entrada e;
  e.n = n;
  for (int i = 0; i < n; ++i)
  {
    e.d.push_back(i);
    e.t.push_back(i);
  }

  return e;
}

Entrada Problema2::generar_instancia_peor_caso(int n)
{
  Entrada e;
  e.n = n;
  for (int i = 0; i < n; ++i)
  {
    e.d.push_back(i);
    e.t.push_back(i);
  }
  
  return e;
}

Entrada Problema2::generar_instancia_aleatoria(int n)
{
  Entrada e;
  e.n = n;
  for (int i = 0; i < n; ++i)
  {
    e.d.push_back(i);
    e.t.push_back(i);
  }
  
  return e;
}