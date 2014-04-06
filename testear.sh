if (( $# != 1 )); then
 printf "Modo de uso: $0 <problema>\n"
 printf "Ejemplo:\n"
 printf "\t$0 problema2\n"
 exit
fi

PROBLEMA=$1
EJECUTABLE=$(dirname $0)/bin/$PROBLEMA
PATH_ENTRADAS=$(dirname $0)/tests/$PROBLEMA

CANT_TESTS=$(ls -1 $PATH_ENTRADAS | wc -l)
if (( $CANT_TESTS == 0 )); then
 printf "No hay tests para $PROBLEMA.\n"
 exit
fi
 
for F_IN in $PATH_ENTRADAS/*.in
do
 echo "-------------------------"
 F_OUT="${F_IN%.*}.out"

 printf "cat $F_IN | sed '/^#/ d' | sed '/^$/d' | $EJECUTABLE\n"
 SALIDA_ESPERADA=$(cat $F_OUT | sed '/^#/ d' | sed '/^$/d')
 SALIDA=$(cat $F_IN | sed '/^#/ d' | sed '/^$/d' | $EJECUTABLE)

 if [[ $? == 0 ]] ; then
   if [ "$SALIDA" == "$SALIDA_ESPERADA" ];
   then
    printf "Resultado: (✔)\n"
   else
    printf "Resultado: (x)\n"
    printf "Salida:\n"
    printf "$SALIDA\n"
    printf "Salida esperada:\n"
    printf "$SALIDA_ESPERADA\n"
   fi
 else
  printf "Resultado: (x)\n!! código de retorno distinto de 0, posible segfault.\n"
 fi
done