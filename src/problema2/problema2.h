#ifndef PROBLEMA_2_H
#define PROBLEMA_2_H

#include <vector>

namespace Problema2
{
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

	struct Entrada
	{
	  int cant_piezas;
	  std::vector<Pieza> piezas;
	};

	struct Salida
	{
	  std::vector<Pieza> piezas;
	  int perdida_total;
	};

	bool leer_entrada(Entrada& e);
	void escribir_salida(Salida& s);

	Salida resolver(const Entrada& e);

	Entrada generar_instancia_mejor_caso(int n);
	Entrada generar_instancia_peor_caso(int n);
	Entrada generar_instancia_aleatoria(int n);
}

#endif /* PROBLEMA_2_H */