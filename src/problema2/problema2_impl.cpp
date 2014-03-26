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

struct Pieza
{
  Pieza(int indice, int perdida, int tiempo)
    : indice(indice), perdida(perdida), tiempo(tiempo) {}
  static bool comparar_piezas(const Pieza& lhs, const Pieza& rhs)
  {
    return lhs.tiempo * rhs.perdida < rhs.tiempo * lhs.perdida;
  }

  int indice;
  int perdida;
  int tiempo;
};


Salida Problema2::resolver(Entrada& e)
{
  Salida s;
  int& cant_piezas = e.n;
  vector<int>& perdidas = e.d;
  vector<int>& tiempos = e.t;
  vector<int>& indices = s.i;
  int& perdida_total = s.P;

  vector<Pieza> piezas;
  for (int i = 0; i < cant_piezas; ++i)
    piezas.push_back(Pieza(i+1, perdidas[i], tiempos[i]));

  sort(piezas.begin(), piezas.end(), Pieza::comparar_piezas);

  int acum_tiempo = 0;
  for (vector<Pieza>::const_iterator i = piezas.begin(); i != piezas.end(); ++i)
  {
    acum_tiempo += i->tiempo;
    perdida_total += acum_tiempo * i->perdida;
    indices.push_back(i->indice);
  }

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