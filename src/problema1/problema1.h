#ifndef PROBLEMA_1_H
#define PROBLEMA_1_H

#include <vector>

namespace Problema1
{
	struct Entrada
	{
	  int cant_dias_inspeccion;
	  int cant_dias;
	  std::vector<int> dias;
	};

	struct Salida
	{
	  int dia_inicial;
	  int max_cant_camiones;
	};

	bool leer_entrada(Entrada& e);
	void escribir_salida(Salida& s);

	Salida resolver(const Entrada& e);

	Entrada generar_instancia_mejor_caso(int n);
	Entrada generar_instancia_peor_caso(int n);
	Entrada generar_instancia_aleatoria(int n);
}

#endif /* PROBLEMA_1_H */