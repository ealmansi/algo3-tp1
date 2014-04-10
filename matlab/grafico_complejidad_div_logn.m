function grafico_complejidad_div_logn(ms, label)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2)./log(ms(:,1)));
  title([label ' : ' 'Tiempo de ejecucion / logaritmica vs Tamano de entrada']);
  ylabel('Tiempo de ejecucion / logaritmica (ns/log(n))');
  xlabel('Tamano de entrada (n)');
  legend('T(n)/log(n)');
end