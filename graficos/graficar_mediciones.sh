if (( $# != 1 )); then
 printf "Modo de uso: $0 <problema>\n"
 printf "Ejemplo:\n"
 printf "\t$0 problema2\n"
 exit
fi

if ! which matlab > /dev/null; then
  printf "El ejecutable de Matlab no está en el path.\n"
  printf "Para agregarlo, correr desde la línea de comandos:\n"
  printf "\texport PATH=\"\$PATH:/usr/local/MATLAB/R2013a/bin\""
  printf "\n"
  printf "Modificando el path al directorio bin de Matlab apropiadamente.\n"
  exit
fi

PROBLEMA=$1
DIR_SCRIPTS_MATLAB=$(dirname $0)/../matlab

matlab -nodisplay -nosplash -r "try, addpath('$DIR_SCRIPTS_MATLAB');graficar_mediciones('$PROBLEMA'), catch, end, quit" > /dev/null