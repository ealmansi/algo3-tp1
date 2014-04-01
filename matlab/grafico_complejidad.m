function grafico_complejidad(ms)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2));
  title('Tiempo de ejecucion vs Tamano de entrada');
  ylabel('Tiempo de ejecucion (ns)');
  xlabel('Tamano de entrada (n)');
  legend('T(n)');
end