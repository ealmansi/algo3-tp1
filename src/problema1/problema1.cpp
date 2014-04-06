#include "problema1.h"

using namespace std;
using namespace Problema1;

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
