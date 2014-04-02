if (( $# != 1 )); then
 printf "Modo de uso: $0 <problema>\n"
 printf "Ejemplo:\n"
 printf "\t$0 problema2\n"
 exit
fi

PROBLEMA=$1
EJECUTABLE=$(dirname $0)/../bin/$PROBLEMA
PATH_ENTRADAS=$(dirname $0)/$PROBLEMA

CANT_TESTS=$(ls -1 $PATH_ENTRADAS | wc -l)
if (( $CANT_TESTS == 0 )); then
 printf "No hay tests para $PROBLEMA.\n"
 exit
fi
 
for F_IN in $PATH_ENTRADAS/*.in
do
 F_OUT="${F_IN%.*}.out"
 ENTRADA=$(cat $F_IN | sed '/^#/ d' | sed '/^$/d')
 SALIDA_ESPERADA=$(cat $F_OUT | sed '/^#/ d' | sed '/^$/d')
 SALIDA=$(echo $ENTRADA | $EJECUTABLE)
 echo $SALIDA
 if [ "$SALIDA" == "$SALIDA_ESPERADA" ];
 then
  echo "Test $F_IN (✔)"
 else
  echo "Test $F_IN (x)"
 fi
done