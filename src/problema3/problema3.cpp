#include "problema3.h"

using namespace std;
using namespace Problema3;

int main()
{
  while(true)
  {
    Entrada e;
    if(!leer_entrada(e)) break;
    Salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}
