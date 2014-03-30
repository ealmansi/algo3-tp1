#ifndef PROBLEMA_3_H
#define PROBLEMA_3_H

#include <vector>

namespace Problema3
{
	struct Pieza
	  {
	  	Pieza(int indice, int sup, int izq, int der, int inf)
	  		: indice(indice), sup(sup), izq(izq), der(der), inf(inf) {}
	  	int indice;
	  	int sup;
	  	int izq;
	  	int der;
	  	int inf;
	  };
	
	
	struct Entrada
	{
	  int n;
	  int m;
	  int c;
	  std::vector<Pieza> piezas;
	};

	struct Salida
	{
	  std::vector<std::vector<int> > casillas;
	  
	};

	struct Tablero
	{
	  std::vector<std::vector<Pieza> > casillas;
	  int fichas;
	};
	
	bool leer_entrada(Entrada& e);
	void escribir_salida(Salida& s);

	Salida resolver(const Entrada& e);

	Entrada generar_instancia_unidimensional(int n);
	Entrada generar_instancia_cuadrada(int n);
	
	void BT(Tablero& mejorHastaAhora,Tablero& trabajoConEste, int fila, int columna, const Entrada& e, std::vector<bool> estaDisp); 
	bool esValido(Tablero& t, int fila, int columna);
	bool valeLaPena(Tablero& t, int fila, int columna, const Entrada& e);
	void SiguientePos(int& sigFila,int& sigCol,int& fila,int& columna,const Entrada& e);
}

#endif /* PROBLEMA_3_H */
