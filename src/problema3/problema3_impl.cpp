#include <iostream>
#include <vector>
#include <algorithm>
#include "problema3.h"

#define DEBUG() {cout << __FUNCTION__ << ":" << __LINE__ << endl;}
#define EXPR(expr) {cout << #expr << ": " << (expr) << endl;}
#define EXPRS(a, b) {cout << #a << ": " << (a) << ", " << #b << ": " << (b) << endl;}

using namespace std;
using namespace Problema3;

long acumulador;
typedef Entrada::Pieza Pieza;


struct Tablero
{
  Tablero(int n, int m) : cantPiezas(0), casilleros(n, vector<int>(m, 0)) {}

  int cantPiezas;
  vector<vector<int> > casilleros;
};

bool Problema3::leer_entrada(Entrada &e)
{
  cin >> e.n;
  cin >> e.m;
  cin >> e.c;
  for (int i = 0; i < e.n * e.m; ++i)
  {
    int sup, izq, der, inf;
    cin >> sup;
    cin >> izq;
    cin >> der;
    cin >> inf;
    e.piezas.push_back(Pieza(i + 1, sup, izq, der, inf));
  }

  return true;
}

void Problema3::escribir_salida(Salida &s)
{
  for (vector<vector<int> >::const_iterator i = s.casilleros.begin(); i != s.casilleros.end(); ++i)
  {
    vector<int>::const_iterator j;
    for (j = i->begin(); j + 1 != i->end(); ++j)
      cout << *j  << " ";
    cout << *j  << endl;
  }
}

static void resolverBacktracking(int i, int j, Tablero &solucionParcial, Tablero &solucionOptima, vector<bool> &piezaDisponible, const Entrada &e);
static bool llamarRecursivamente(int i, int j, Tablero &solucionParcial, Tablero &solucionOptima, vector<bool> &piezaDisponible, const Entrada &e);
static void calcularSiguientePos(int &sig_i, int &sig_j, int i, int j, const Entrada &e);
static bool esCompatible(int p, int i, int j, Tablero &solucionParcial, const Entrada &e);
static void colocarPieza(int p, int i, int j, Tablero &tablero, vector<bool> &piezaDisponible);
static void removerPieza(int p, int i, int j, Tablero &tablero, vector<bool> &piezaDisponible);
static void sumarUnColor(Entrada &e, int pieza, int color);

Salida Problema3::resolver(const Entrada &e)
{
	Tablero solucionParcial(e.n, e.m), solucionOptima(e.n, e.m);
  vector<bool> piezaDisponible(e.n * e.m, true);
  resolverBacktracking(0, 0, solucionParcial, solucionOptima, piezaDisponible, e);

  Salida s;
  s.casilleros = solucionOptima.casilleros;
  return s;
}

void resolverBacktracking(int i, int j, Tablero &solucionParcial, Tablero &solucionOptima, vector<bool> &piezaDisponible, const Entrada &e)
{
  acumulador++;
  int sig_i, sig_j;
  calcularSiguientePos(sig_i, sig_j, i, j, e);

  for (int indicePieza = 1; indicePieza <= e.n * e.m; ++indicePieza)
  {
    if (!piezaDisponible[indicePieza - 1]) continue;
    if (!esCompatible(indicePieza, i, j, solucionParcial, e)) continue;

    colocarPieza(indicePieza, i, j, solucionParcial, piezaDisponible);

    if (solucionOptima.cantPiezas < solucionParcial.cantPiezas)
      solucionOptima = solucionParcial;

    if (llamarRecursivamente(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e))
      resolverBacktracking(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e);

    removerPieza(indicePieza, i, j, solucionParcial, piezaDisponible);
  }

  if (llamarRecursivamente(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e))
    resolverBacktracking(sig_i, sig_j, solucionParcial, solucionOptima, piezaDisponible, e);
}

bool llamarRecursivamente(int i, int j, Tablero &solucionParcial, Tablero &solucionOptima, vector<bool> &piezaDisponible, const Entrada &e)
{
  if (solucionOptima.cantPiezas == e.n * e.m)
    return false;

  if (e.n <= i || e.m <= j)
    return false;

  int espaciosRestantes = e.n * e.m - (i * e.m + j);
  vector<int> coloresNecesarios(e.c, 0);
  int f, c, indice;
  f = (i == 0) ? 0 : i - 1;
  c = (i == 0) ? 0 : j;
  for (; f != i && c != j ; calcularSiguientePos(f, c, f, c, e))
  {
    indice = solucionParcial.casilleros[f][c];
    if (indice != 0)
      ++coloresNecesarios[e.piezas[indice - 1].inf - 1];
  }

  for (int h = 0; h < e.n * e.m; ++h)
    if (piezaDisponible[h])
      --coloresNecesarios[e.piezas[h].sup - 1];

  for (int h = 0; h < e.c; ++h)
    if (coloresNecesarios[h] > 0)
      espaciosRestantes -= coloresNecesarios[h];

  if (solucionParcial.cantPiezas + espaciosRestantes <= solucionOptima.cantPiezas)
    return false;

  return true;
}

void calcularSiguientePos(int &sig_i, int &sig_j, int i, int j, const Entrada &e)
{
  sig_i = i + (j + 1) / e.m;
  sig_j = (j + 1) % e.m;
}

bool esCompatible(int indicePieza, int i, int j, Tablero &solucionParcial, const Entrada &e)
{
  const Pieza &pieza = e.piezas[indicePieza - 1];
  if (0 < j)
  {
    int indicePiezaIzq = solucionParcial.casilleros[i][j - 1];
    if (0 < indicePiezaIzq)
      if (pieza.izq != e.piezas[indicePiezaIzq - 1].der)
        return false;
  }
  if (0 < i)
  {
    int indicePiezaSup = solucionParcial.casilleros[i - 1][j];
    if (0 < indicePiezaSup)
      if (pieza.sup != e.piezas[indicePiezaSup - 1].inf)
        return false;
  }

  return true;
}

void colocarPieza(int indicePieza, int i, int j, Tablero &tablero, vector<bool> &piezaDisponible)
{
  tablero.casilleros[i][j] = indicePieza;
  ++tablero.cantPiezas;
  piezaDisponible[indicePieza - 1] = false;
}

void removerPieza(int indicePieza, int i, int j, Tablero &tablero, vector<bool> &piezaDisponible)
{
  tablero.casilleros[i][j] = 0;
  --tablero.cantPiezas;
  piezaDisponible[indicePieza - 1] = true;
}

Entrada Problema3::generar_instancia_unidimensional(int n)
{
  Entrada e;
  e.n = n;
  e.m = 1;
  e.c = 10;
  for (int i = 0; i < n * 1; ++i)
    e.piezas.push_back(Pieza(i + 1, (1 + 2 )  + 1, (1 + 3 )  + 1, (1 + 5 )  + 1, (1 + 7 )  + 1));

	EXPR(e.n);
		EXPR(e.m);
					EXPR(e.c);
	for (int i = 0; i < n * 1; ++i)
		EXPR(e.piezas[i].inf);

  return e;
}

Entrada Problema3::generar_instancia_cuadrada(int n)
{
  Entrada e;
  e.n = n;
  e.m = n;
  e.c = 10;
  for (int i = 0; i < n * n; ++i)
    e.piezas.push_back(Pieza(i + 1, (1 + 2 )  + 1, (1 + 3 )  + 1, (1 + 5 )  + 1, (1 + 7)  + 1));
  return e;
}

void Problema3::generar_toda_instancia(int n)
{
  Entrada e;
  e.n = n;
  e.m = n;
  e.c = (n*n)*4;
  long total = 0;
  for (int i = 1 ; i <= n * n; ++i)
  {
    e.piezas.push_back(Pieza(i,1,1,1,1));
  }
  for (int j = 0 ; j < ((n*n)*4);++j)
  {
    for (int i = 0 ; i < ((n*n)*4);++i)
    {
      acumulador = 0;
      sumarUnColor(e,0,0);
      Problema3::resolver(e);
      total += acumulador;
    }
  }
  std::cout <<  n << " " << total << endl;
}

void sumarUnColor(Entrada &e, int pieza, int color)
{
  switch (color)
  {
    case 0:
      if(e.piezas[pieza].sup == e.c)
      {
        e.piezas[pieza].sup = 1;
        sumarUnColor(e,pieza,color+1); 
      }
      else{e.piezas[pieza].sup++;}
      break;
    case 1:
      if(e.piezas[pieza].inf == e.c)
      {
        e.piezas[pieza].inf = 1;
        sumarUnColor(e,pieza,color+1); 
      }
      else{++e.piezas[pieza].inf;}
      break;
    case 2:
      if(e.piezas[pieza].izq == e.c)
      {
        e.piezas[pieza].izq = 1;
        sumarUnColor(e,pieza,color+1); 
      }
      else{++e.piezas[pieza].izq;}
      break;
    case 3:
      if(e.piezas[pieza].der == e.c)
      {
        e.piezas[pieza].der = 1;
        sumarUnColor(e,pieza+1,0); 
      }
      else{++e.piezas[pieza].der;}
      break;
  }
}