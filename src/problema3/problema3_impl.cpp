#include <iostream>
#include <vector>
#include <algorithm>
#include "problema3.h"

#define DEBUG() {cout << __FUNCTION__ << ":" << __LINE__ << endl;}
#define EXPR(expr) {cout << #expr << ": " << (expr) << endl;}
#define EXPRS(a, b) {cout << #a << ": " << (a) << ", " << #b << ": " << (b) << endl;}

using namespace std;
using namespace Problema3;
typedef Entrada::Pieza Pieza;

struct Tablero
{
  Tablero(int n, int m) : cantPiezas(0), casilleros(n, vector<int>(m, 0)) {}

  int cantPiezas;
  vector<vector<int> > casilleros;
};
  
bool Problema3::leer_entrada(Entrada& e)
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
    e.piezas.push_back(Pieza(i+1, sup, izq, der, inf));
  }

  return true;
}

void Problema3::escribir_salida(Salida& s)
{
  for (vector<vector<int> >::const_iterator i = s.casilleros.begin(); i != s.casilleros.end(); ++i)
  {
    for (vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
      cout << *j  << " ";
    cout << endl;
  }
}

static void resolverBacktracking(int i, int j, Tablero& solucionParcial, Tablero& solucionOptima, vector<bool>& piezaDisponible, const Entrada& e);
static bool llamarRecursivamente(int i, int j, Tablero& solucionParcial, Tablero& solucionOptima, vector<bool>& piezaDisponible, const Entrada& e);
static void calcularSiguientePos(int& sig_i, int& sig_j, int i, int j, const Entrada& e);
static bool esCompatible(int p, int i, int j, Tablero& solucionParcial, const Entrada& e);
static void colocarPieza(int p, int i, int j, Tablero& tablero, vector<bool>& piezaDisponible);
static void removerPieza(int p, int i, int j, Tablero& tablero, vector<bool>& piezaDisponible);

Salida Problema3::resolver(const Entrada& e)
{
  Salida s;

  Tablero solucionParcial(e.n, e.m), solucionOptima(e.n, e.m);
  vector<bool> piezaDisponible(e.n * e.m, true);

  resolverBacktracking(0, 0, solucionParcial, solucionOptima, piezaDisponible, e);

  s.casilleros = solucionOptima.casilleros;
  return s;
}

void resolverBacktracking(int i, int j, Tablero& solucionParcial, Tablero& solucionOptima, vector<bool>& piezaDisponible, const Entrada& e)
{
  int sig_i, sig_j;
  calcularSiguientePos(sig_i, sig_j, i, j, e);

  for (int indicePieza = 1; indicePieza <= e.n * e.m; ++indicePieza)
  {
    if (!piezaDisponible[indicePieza-1]) continue;
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

bool llamarRecursivamente(int i, int j, Tablero& solucionParcial, Tablero& solucionOptima, vector<bool>& piezaDisponible, const Entrada& e)
{
  if (solucionOptima.cantPiezas == e.n * e.m)
    return false;

  if (e.n <= i || e.m <= j)
    return false;

  int espaciosRestantes = e.n * e.m - (i * e.m + j);
  //poda 2.0
	vector<int> coloresNecesarios(e.c,0);
	int f, c ;
	if(i != 0)
	{
	f = i-1;
	c = j;
	}
	else
	{
	f = c = 0;
	}
	int indice;
	for(;f != i && c != j ;calcularSiguientePos(f,c,f,c,e))
	{
		indice = solucionParcial.casilleros[f][c];
		if(indice != 0)
		{
			++coloresNecesarios[e.piezas[indice -1].inf -1];
		}
	}
  for(int h = 0; h < e.n * e.m; ++h)
  {
  	if(piezaDisponible[h])
  	{
  		--coloresNecesarios[e.piezas[h -1].sup -1];
  	}
  }
  for(int h = 0; h < e.c;++h)
  {
  	if(coloresNecesarios[h] > 0)
  	{
  		espaciosRestantes -= coloresNecesarios[h]; 
  	}
  }
  
  //
  if (solucionParcial.cantPiezas + espaciosRestantes <= solucionOptima.cantPiezas)
    return false;

  return true;
}

void calcularSiguientePos(int& sig_i, int& sig_j, int i, int j, const Entrada& e)
{
  sig_i = i + (j + 1) / e.m;
  sig_j = (j + 1) % e.m;
}

bool esCompatible(int indicePieza, int i, int j, Tablero& solucionParcial, const Entrada& e)
{
  const Pieza& pieza = e.piezas[indicePieza-1];
  if (0 < j)
  {
    int indicePiezaIzq = solucionParcial.casilleros[i][j-1];
    if (0 < indicePiezaIzq)
      if (pieza.izq != e.piezas[indicePiezaIzq-1].der)
        return false;
  }
  if (0 < i)
  {
    int indicePiezaSup = solucionParcial.casilleros[i-1][j];
    if (0 < indicePiezaSup)
      if (pieza.sup != e.piezas[indicePiezaSup-1].inf)
        return false;
  }

  return true;
}

void colocarPieza(int indicePieza, int i, int j, Tablero& tablero, vector<bool>& piezaDisponible)
{
  tablero.casilleros[i][j] = indicePieza;
  ++tablero.cantPiezas;
  piezaDisponible[indicePieza-1] = false;
}

void removerPieza(int indicePieza, int i, int j, Tablero& tablero, vector<bool>& piezaDisponible)
{
  tablero.casilleros[i][j] = 0;
  --tablero.cantPiezas;
  piezaDisponible[indicePieza-1] = true;
}

Entrada Problema3::generar_instancia_unidimensional(int n)
{
  Entrada e;
  e.n = n;
  e.m = 1;
  e.c = 10;
  for (int i = 0; i < n * 1; ++i)
    e.piezas.push_back(Pieza(i+1, i*2 % e.c, i*3 % e.c, i*5 % e.c, i*7 % e.c));
  return e;
}

Entrada Problema3::generar_instancia_cuadrada(int n)
{
  Entrada e;
  e.n = n;
  e.m = n;
  e.c = 10;
  for (int i = 0; i < n * n; ++i)
    e.piezas.push_back(Pieza(i+1, i*2 % e.c, i*3 % e.c, i*5 % e.c, i*7 % e.c));
  return e;
}
