function grafico_complejidad_div_n(ms, label)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2)./ms(:,1));
  title([label ' : ' 'Tiempo de ejecucion / lineal vs Tamano de entrada']);
  ylabel('Tiempo de ejecucion / lineal (ns / n)');
  xlabel('Tamano de entrada (n)');
  legend('T(n) / n');
end