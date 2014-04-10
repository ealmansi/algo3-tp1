function graficar_mediciones(problema)
  dir_raiz = [fileparts(mfilename('fullpath')) '/' '..'];
  dir_mediciones = [dir_raiz '/' 'mediciones' '/' problema];
  dir_graficos = [dir_raiz '/' 'graficos' '/' problema];

  if problema == 'problema1'
    tipo_medicion = 'problema1_aleatoria_10000';
    ms = cargar_mediciones([dir_mediciones '/' tipo_medicion '.csv']);
    grafico_complejidad(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '.eps'],'epsc');
    grafico_complejidad_div_n(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_n' '.eps'],'epsc');
    grafico_complejidad_div_logn(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_logn' '.eps'],'epsc');
    grafico_complejidad_div_nlogn(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_nlogn' '.eps'],'epsc');

    tipo_medicion1 = 'problema1_ordenada_aleatoria_10000';
    tipo_medicion2 = 'problema1_ordenada_siempre_actualiza_10000';
    tipo_medicion3 = 'problema1_ordenada_todos_distintos_10000';
    ms1 = cargar_mediciones([dir_mediciones '/' tipo_medicion1 '.csv']);
    ms2 = cargar_mediciones([dir_mediciones '/' tipo_medicion2 '.csv']);
    ms3 = cargar_mediciones([dir_mediciones '/' tipo_medicion3 '.csv']);
    grafico_comparacion_complejidades(ms1, 'Aleatoria', ms2, 'Siempre actualiza', ms3, 'Todos distintos');
    saveas(gca, [dir_graficos '/' tipo_medicion1 '_vs_' tipo_medicion2 '_vs_' tipo_medicion3 '.eps'],'epsc');

  else if problema == 'problema2'

    tipo_medicion = 'problema2_aleatoria_10000';
    ms = cargar_mediciones([dir_mediciones '/' tipo_medicion '.csv']);
    grafico_complejidad(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '.eps'],'epsc');
    grafico_complejidad_div_n(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_n' '.eps'],'epsc');
    grafico_complejidad_div_logn(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_logn' '.eps'],'epsc');
    grafico_complejidad_div_nlogn(ms, 'Instancias aleatorias');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_nlogn' '.eps'],'epsc');

    tipo_medicion = 'problema2_ordenada_8000';
    ms = cargar_mediciones([dir_mediciones '/' tipo_medicion '.csv']);
    grafico_complejidad(ms, 'Instancias ordenadas (sin invocar a sort)');
    saveas(gca, [dir_graficos '/' tipo_medicion '.eps'],'epsc');
    grafico_complejidad_div_n(ms, 'Instancias ordenadas (sin invocar a sort)');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_n' '.eps'],'epsc');
    grafico_complejidad_div_logn(ms, 'Instancias ordenadas (sin invocar a sort)');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_logn' '.eps'],'epsc');
    grafico_complejidad_div_nlogn(ms, 'Instancias ordenadas (sin invocar a sort)');
    saveas(gca, [dir_graficos '/' tipo_medicion '_div_nlogn' '.eps'],'epsc');

  else
    files = dir([dir_mediciones '/' '*.csv']);
    for file = files'
      [~,tipo_medicion,~] = fileparts(file.name);
      ms = cargar_mediciones([dir_mediciones '/' tipo_medicion '.csv']);
      grafico_complejidad(ms, '');
      saveas(gca, [dir_graficos '/' tipo_medicion '.eps'],'epsc');
    end
  end
end