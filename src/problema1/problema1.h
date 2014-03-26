#ifndef PROBLEMA_1_H
#define PROBLEMA_1_H

#include <vector>

namespace Problema1
{
	struct Entrada
	{
	  int D;
	  int n;
	  std::vector<int> d;
	};

	struct Salida
	{
	  int d;
	  int c;
	};

	bool leer_entrada(Entrada& e);
	void escribir_salida(Salida& s);

	Salida resolver(Entrada& e);

	Entrada generar_instancia_mejor_caso(int n);
	Entrada generar_instancia_peor_caso(int n);
	Entrada generar_instancia_aleatoria(int n);
}

#endif /* PROBLEMA_1_H */