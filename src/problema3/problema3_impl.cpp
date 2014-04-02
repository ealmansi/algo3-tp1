#include <iostream>
#include <vector>
#include <algorithm>

#include "problema3.h"

using namespace std;
using namespace Problema3;

#define DEBUG(str) {cout << #str << endl;}
#define EXPR(expr) {cout << #expr << " " << (expr) << endl;}

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
  cout << "hola" << endl;
  for (vector<vector<int> >::const_iterator i = s.casillas.begin(); i != s.casillas.end(); ++i)
  {
    for (vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
      cout << *j  << " ";
    cout << endl;
  }
}

Salida Problema3::resolver(const Entrada& e)
{
  Tablero mejorHastaAhora, trabajoConEste;
  vector<bool> estaDisp(e.n * e.m, true);
  for (int i = 0; i < e.n; i++) {
    mejorHastaAhora.casillas.push_back(vector<Pieza>());
    trabajoConEste.casillas.push_back(vector<Pieza>());
    for (int j = 0; j < e.m; j++) {
      mejorHastaAhora.casillas[i].push_back(Pieza(0,0,0,0,0));
      trabajoConEste.casillas[i].push_back(Pieza(0,0,0,0,0));
    } 
  }
  //vector<vector<bool> > estaDisp = 
  ///n filas, m columnas
  //int cant
  ///salida final, salida que trabajo, fila, columna, entrada
  ///fila y columna son los que voy a escribir AHORA
  BT(mejorHastaAhora, trabajoConEste, 0, 0, e, estaDisp);

  Salida s;
  s.casillas = vector<vector<int> >();
  for (int i = 0; i < e.n; i++){
    s.casillas.push_back(vector<int>());
    for (int j = 0; j < e.m; j++){
      s.casillas[i].push_back(mejorHastaAhora.casillas[i][j].indice);
    } 
  }

  return s;
}
void Problema3::BT(Tablero& mejorHastaAhora, Tablero& trabajoConEste, int fila, int columna, const Entrada& e, vector<bool> estaDisp){
	
	///aca va el problema
  DEBUG("trabajo pos:");
  EXPR(fila);
  EXPR(columna);
  int sigFila;
  int sigCol;
  siguientePos(sigFila , sigCol , fila , columna , e); //logica para encontrar la sig pos
  
  if(trabajoConEste.fichas > mejorHastaAhora.fichas){  //si es mejor lo guardo

		mejorHastaAhora.fichas = trabajoConEste.fichas;

		for (int i = 0; i<e.n; i++){
 			mejorHastaAhora.casillas[i] = trabajoConEste.casillas[i];
 			} 
	}
	DEBUG("mejor hasta ahora");
	EXPR(mejorHastaAhora.fichas);
  for(int i = 0; i < e.n*e.m; i++){   //recorro todas las piezas
  	if(!estaDisp[i]) continue;	 										//para las que todavia no puse
	DEBUG("pongo la ficha");
	EXPR(i);
    //if(trabajoConEste.casillas[fila][columna].indice == 0){
      trabajoConEste.fichas++;
    //} //si es la primera pieza q pongo en ese casillero sumo 1 a la cant de piezas (si no lo es ya lo sume antes)
    trabajoConEste.casillas[fila][columna] = e.piezas[i];   //pongo la pieza en el tablero
    estaDisp[i] = false;                  //la marco como no disp
  	if(esValido(trabajoConEste,fila,columna)){
  	  if(valeLaPena(trabajoConEste,fila,columna,e,mejorHastaAhora.fichas)){ //si llego a una instancia valida y q puede llegar a ser optima
  		  BT(mejorHastaAhora,trabajoConEste,sigFila,sigCol,e,estaDisp);  //recursion
      }
      else if(fila == e.n -1 && columna == e.m -1){
        if(trabajoConEste.fichas > mejorHastaAhora.fichas){  //si es mejor lo guardo

		      mejorHastaAhora.fichas = trabajoConEste.fichas;

		      for (int i = 0; i<e.n; i++){
 			      mejorHastaAhora.casillas[i] = trabajoConEste.casillas[i];
 			    } 
	      }
      }  	
  	}
  	estaDisp[i] = true; 			//vuelvo a habilitar la pieza
    trabajoConEste.fichas--;
    trabajoConEste.casillas[fila][columna] = Pieza(0,0,0,0,0);
  }
	/// Caso ficha blanca
  //if(trabajoConEste.casillas[fila][columna].indice != 0){
    //trabajoConEste.fichas--;
  //} //si puse alguna pieza en esa pos reduzco el contador
  trabajoConEste.casillas[fila][columna] = Pieza(0,0,0,0,0);      //pongo la ficha blanca
  if(valeLaPena(trabajoConEste,fila,columna,e,mejorHastaAhora.fichas)){            //si puede llegar a ser optima (seguro es valido)
    BT(mejorHastaAhora,trabajoConEste,sigFila,sigCol,e,estaDisp);     //recursion
	}
	DEBUG("vuelvo para atras");
	return;
}

bool Problema3::esValido(Tablero& t, int fila, int columna){
	bool res = true;
	if(fila !=0){ ///Si no es la primera fila
		res = res && (t.casillas[fila][columna].sup == t.casillas[fila-1][columna].inf || t.casillas[fila][columna].sup == 0 || t.casillas[fila-1][columna].inf == 0);
	}
	if(columna !=0){ ///Si no es la primera columna
		res = res && (t.casillas[fila][columna].izq == t.casillas[fila][columna-1].der || t.casillas[fila][columna].izq == 0 || t.casillas[fila][columna-1].der == 0);
	}
	return res;
}

bool Problema3::valeLaPena(Tablero& t, int fila, int columna, const Entrada& e, int maxHastaAhora){
	if(fila == e.n -1 && columna == e.m -1){
    return false;
  }
  
  return maxHastaAhora < t.fichas + e.m - columna -1 + (e.n - fila -1) * e.m;
}

void Problema3::siguientePos(int& sigFila,int& sigCol,int& fila,int& columna,const Entrada& e){
	sigFila = fila;
	sigCol = columna;
	if(columna == e.m - 1){
		sigFila++;
		sigCol = 0;
	}
	else{sigCol++;}
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
