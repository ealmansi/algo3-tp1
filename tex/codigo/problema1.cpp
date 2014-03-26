Salida Problema1::resolver(Entrada& e)
{
  int& cant_dias_inspeccion = e.D;
  int& cant_dias = e.n;
  vector<int>& dias = e.d;

  int dia_inicial = -1;
  int max_cant_camiones = -1;
  int i, j, cant_camiones;

  sort(dias.begin(), dias.end());
  
  i = j = 0;
  for (; i < cant_dias; ++i)
  {
    for (; (j < cant_dias) && (dias[j] - dias[i] < cant_dias_inspeccion); ++j)
      ;
    cant_camiones = j - i;
    if(max_cant_camiones < cant_camiones)
    {
      max_cant_camiones = cant_camiones;
      dia_inicial = dias[i];
    }
  }

  Salida s = {.d = dia_inicial, .c = max_cant_camiones};
  return s;
}