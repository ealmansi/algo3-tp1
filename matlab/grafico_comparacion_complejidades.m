function grafico_comparacion_complejidades(ms1, label1, ms2, label2, ms3, label3)
  if ~isfloat(ms1) || size(ms1,2) ~= 2 || ~isfloat(ms2) || size(ms2,2) ~= 2 || ~isfloat(ms3) || size(ms3,2) ~= 2
      error('Entrada inválida.')
  end

  figure;
  hold on;
  plot(ms1(:,1),ms1(:,2),'g');
  plot(ms2(:,1),ms2(:,2),'b');
  plot(ms3(:,1),ms3(:,2),'r');
  title([label1 ' vs ' label2 ' vs ' label3]);
  ylabel('Tiempo de ejecucion (ns)');
  xlabel('Tamano de entrada (n)');
  legend({label1, label2, label3});
end