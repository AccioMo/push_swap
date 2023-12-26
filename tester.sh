#!/bin/bash

i=0
G='\033[1;32m'
R='\033[1;31m'
B='\033[1;34m'
W='\033[0m'
T=0
MIN=99999999999
MAX=0
while [ $i -le 1000 ]
do
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	A=`./push_swap $ARG`
	N=`./push_swap $ARG | wc -l`
	V=$(./push_swap $ARG | ./checker_linux $ARG)
	i=$(($i + 1))
	T=$(($T + $N))
	MIN=$(($MIN > $N ? $N : $MIN))
	MAX=$(($MAX < $N ? $N : $MAX))
	if [ "$V" == "KO" ]; then C="$R"; else C="$G"; fi
	echo -e "$N $C$V$W"
	if [ $N -gt 699 ]
	then
		echo -e "$R ERROR"
		echo -e "$ARG  $W"
	fi
done
echo -e "$B Average: $(($T / 1000)); Min: $MIN; Max: $MAX $W"
