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

    % tipo_medicion = 'problema2_aleatoria_10000';
    % ms = cargar_mediciones([dir_mediciones '/' tipo_medicion '.csv']);
    % grafico_complejidad(ms, 'Instancias aleatorias');
    % saveas(gca, [dir_graficos '/' tipo_medicion '.eps'],'epsc');
    % grafico_complejidad_div_n(ms, 'Instancias aleatorias');
    % saveas(gca, [dir_graficos '/' tipo_medicion '_div_n' '.eps'],'epsc');
    % grafico_complejidad_div_logn(ms, 'Instancias aleatorias');
    % saveas(gca, [dir_graficos '/' tipo_medicion '_div_logn' '.eps'],'epsc');
    % grafico_complejidad_div_nlogn(ms, 'Instancias aleatorias');
    % saveas(gca, [dir_graficos '/' tipo_medicion '_div_nlogn' '.eps'],'epsc');

    tipo_medicion = 'problema2_ordenada_10000';
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
    
    close all;

    aleatorias_4x4_poda1 = [dir_mediciones '/4x4_aleatorias_poda1.csv'];
    aleatorias_4x4_poda2 = [dir_mediciones '/4x4_aleatorias_poda2.csv'];
    ms1 = double(csvread(aleatorias_4x4_poda1, 1, 0));
    ms2 = double(csvread(aleatorias_4x4_poda2, 1, 0));
    
    figure;
    bar(1:50, [ms1(:,1), ms2(:,1)]);
    title('Comparacion cantidad de llamados recursivos Poda 1 vs Poda 2 (tableros 4 x 4)');
    axis([0 51 0 1.2*max(max(ms1(:,1), ms2(:,1)))]);
    legend({'Poda 1', 'Poda 2'});
    xlabel('Caso');
    ylabel('Cantidad de llamados recursivos');
    saveas(gca, [dir_graficos '/comparacion_podas1y2_llamados_recursivos.eps'],'epsc');

    figure;
    bar(1:50, [ms1(:,2), ms2(:,2)]);
    title('Comparacion tiempo de ejecucion Poda 1 vs Poda 2 (tableros 4 x 4)');
    axis([0 51 0 1.2*max(max(ms1(:,2), ms2(:,2)))]);
    legend({'Poda 1', 'Poda 2'});
    xlabel('Caso');
    ylabel('Tiempo (ns)');
    saveas(gca, [dir_graficos '/comparacion_podas1y2_tiempo.eps'],'epsc');

    % todas_instancias_todas_podas_llamados = [dir_mediciones '/todas_instancias_todas_podas_llamados.csv'];
    % todas_instancias_todas_podas_tiempo = [dir_mediciones '/todas_instancias_todas_podas_tiempo.csv'];
    % ms1 = double(csvread(todas_instancias_todas_podas_llamados, 1, 0));
    % ms2 = double(csvread(todas_instancias_todas_podas_tiempo, 1, 0));

    % figure;
    % subplot(1,3,1);
    % bar(ms1(:,1), ms1(1,2:end));
    % ylabel('Cantidad de llamados recursivos');
    % subplot(1,3,2);
    % bar(ms1(:,1), ms1(2,2:end));
    % xlabel('Tipo de poda (sin podas, Poda 1, Poda 2)');
    % subplot(1,3,3);
    % bar(ms1(:,1), ms1(3,2:end));
    % hold on;
    % plot([1],[1000000],'rx','MarkerSize',10,'LineWidth',3);
    % saveas(gca, [dir_graficos '/comparacion_podas_todas_instancias_llamados.eps'],'epsc');

    % figure;
    % subplot(1,3,1);
    % bar(ms2(:,1), ms2(1,2:end));
    % ylabel('Tiempo de ejecucion total');
    % subplot(1,3,2);
    % bar(ms2(:,1), ms2(2,2:end));
    % xlabel('Tipo de poda (sin podas, Poda 1, Poda 2)');
    % subplot(1,3,3);
    % bar(ms2(:,1), ms2(3,2:end));
    % hold on;
    % plot([1],[1000000],'rx','MarkerSize',10,'LineWidth',3);
    % saveas(gca, [dir_graficos '/comparacion_podas_todas_instancias_tiempo.eps'],'epsc');

  end
end