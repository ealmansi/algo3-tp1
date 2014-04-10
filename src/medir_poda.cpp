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
  for(int i = argv[1]; i <= argv[2]; ++i)
  {
  	Problema3::generar_toda_instancia(i);
  }
  return 0;
}