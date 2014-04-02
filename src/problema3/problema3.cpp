#include "problema3.h"

using namespace std;
using namespace Problema3;

#include <iostream>

int main()
{
  Entrada e;
  leer_entrada(e);
  Salida s = resolver(e);
  escribir_salida(s);

  return 0;
}
