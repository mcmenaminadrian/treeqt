#!/bin/bash

while [ 1 = 1 ]
do
	../memball/memball --cmd --cpu | ../treedraw/treedraw
	sleep 1
done
