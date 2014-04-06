if (( $# != 2 )); then
 printf "Modo de uso: $0 <problema> <max_n>\n"
 printf "Ejemplo:\n"
 printf "\t$0 problema2 1000\n"
 exit
fi

EJECUTABLE=$(dirname $0)/bin/medir_performance
PROBLEMA=$1
DIR_SALIDA=$(dirname $0)/mediciones/$PROBLEMA
HEADER=$(dirname $0)/src/$PROBLEMA/"${PROBLEMA}.h"
FUNCIONES=$(cat $HEADER | grep generar_instancia | sed 's/^.*Entrada //' | sed 's/(int n);$//')
NLIMITE=$2

for FUNCION in $FUNCIONES
do
  CASO=$(echo $FUNCION | sed 's/generar_instancia_//')
  printf "${EJECUTABLE} ${PROBLEMA} ${FUNCION} ${NLIMITE} ${DIR_SALIDA}/${PROBLEMA}_${CASO}_${NLIMITE}.csv\n"
  $EJECUTABLE $PROBLEMA $FUNCION $NLIMITE "${DIR_SALIDA}/${PROBLEMA}_${CASO}_${NLIMITE}.csv"
done