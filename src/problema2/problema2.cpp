#include "problema2.h"

using namespace std;
using namespace Problema2;

int main()
{
  while (true)
  {
    Entrada e;
    if (!leer_entrada(e)) break;
    Salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}
