#!/bin/bash
x=0
y=0
z=5
while [ $x -le 50 ]
do
	echo "Generating $x $y $z map"
	perl map.pl $x $y $z >> "map_${x}_${y}_${z}.txt"
	x=$(( $x + 1 ))
	y=$(( $y + 1 ))
	#z=$(( $z + 1 ))
done
