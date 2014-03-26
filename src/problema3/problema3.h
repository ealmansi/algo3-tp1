#ifndef PROBLEMA_3_H
#define PROBLEMA_3_H

#include <vector>

namespace Problema3
{
	struct Entrada
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

	  int n;
	  int m;
	  int c;
	  std::vector<Pieza> piezas;
	};

	struct Salida
	{
	  std::vector<std::vector<int> > casillas;
	};

	bool leer_entrada(Entrada& e);
	void escribir_salida(Salida& s);

	Salida resolver(const Entrada& e);

	Entrada generar_instancia_unidimensional(int n);
	Entrada generar_instancia_cuadrada(int n);
}

#endif /* PROBLEMA_3_H */