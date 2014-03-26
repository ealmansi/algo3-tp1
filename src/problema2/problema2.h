#ifndef PROBLEMA_2_H
#define PROBLEMA_2_H

#include <vector>

namespace Problema2
{
	struct Entrada
	{
	  int n;
	  std::vector<int> d;
	  std::vector<int> t;
	};

	struct Salida
	{
	  std::vector<int> i;
	  int P;
	};

	bool leer_entrada(Entrada& e);
	void escribir_salida(Salida& s);

	Salida resolver(Entrada& e);

	Entrada generar_instancia_mejor_caso(int n);
	Entrada generar_instancia_peor_caso(int n);
	Entrada generar_instancia_aleatoria(int n);
}

#endif /* PROBLEMA_2_H */