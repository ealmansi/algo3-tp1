#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sys/time.h>

#include "problema3/problema3.h"

using namespace std;

int main(int argc, char const *argv[])
{

	int desde = atoi(argv[1]);
	int hasta = atoi(argv[2]);
  for(int i = desde; i <= hasta; ++i)
  {
  	Problema3::generar_toda_instancia(i);
  }
  return 0;
}