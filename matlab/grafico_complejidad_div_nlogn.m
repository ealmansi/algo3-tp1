function grafico_complejidad_div_nlogn(ms, label)
  if ~isfloat(ms) || size(ms,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  plot(ms(:,1),ms(:,2)./(ms(:,1) .* log(ms(:,1))));
  title([label ' : ' 'Tiempo de ejecucion / linearitmica vs Tamano de entrada']);
  ylabel('Tiempo de ejecucion / linearitmica (ns/(n*log(n)))');
  xlabel('Tamano de entrada (n)');
  legend('T(n)/(n*log(n))');
end