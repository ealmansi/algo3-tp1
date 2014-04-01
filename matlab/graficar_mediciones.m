function graficar_mediciones(varargin)
  for ii=1:length(varargin)
    problema = char(varargin(ii));
    graficar_mediciones_problema(problema);
  end
end

function graficar_mediciones_problema(problema)
  dir_raiz = [fileparts(mfilename('fullpath')) '/' '..'];
  dir_mediciones = [dir_raiz '/' 'mediciones' '/' problema];
  dir_graficos = [dir_raiz '/' 'graficos' '/' problema];

  files = dir([dir_mediciones '/' '*.csv']);
  for file = files'
    [~,tipo_medicion,~] = fileparts(file.name);
    ms = cargar_mediciones([dir_mediciones '/' tipo_medicion '.csv']);
    grafico_complejidad(ms);
    saveas(gca, [dir_graficos '/' tipo_medicion '.eps'],'epsc');
  end
end