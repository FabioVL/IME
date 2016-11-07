#!/bin/sh

while getopts "shi:m:p:c:n:g:" option
do
	case $option in
		h) HELP=1 ;;
		i) IP=$OPTARG ;;
		m) NETMASK=$OPTARG ;;
		p) PLACA=$OPTARG ;;
		c) CANAL=$OPTARG ;;
		n) NOME=$OPTARG ;;
		g) GATEWAY=$OPTARG ;;
		s) SOBRE=1 ;;
	esac
done

if [ $HELP ]; then
	echo "Uso: `basename $0` -i [ip] -m [netmask] -p [placa] -c [canal] -n [nome da rede] -g [gateway]"
	exit 0
fi

if [ $SOBRE ]; then
	echo "Programa que cria uma rede Ad Hoc"
	exit 0
fi	

if [ $IP ]; then
	ip=$IP
else
	echo "Informe o IP a ser usado:"
	read ip
fi

if [ $NETMASK ]; then
	mask=$NETMASK
else 
	echo "Informe a máscara de rede"
	read mask
fi

if [ $PLACA ]; then
	placa=$PLACA
else
	a=1
	ifconfig | sed "s/ .*$//" | sed "/^$/d" > Interfaces
	echo "Informe a placa de rede"
	for i in `cat Interfaces`; do
		echo "$a - $i"
		a=`expr $a + 1`
	done
	read nplaca
	placa=$(sed -n $nplaca' p;' Interfaces)
fi

if [ $CANAL ]; then
	canal=$CANAL
else
	echo "Informe o canal"
	read canal
fi
if [ $NOME ]; then
	nome=$NOME
else
	echo "Informe o nome da rede"
	read nome
fi
if [ $GATEWAY ]; then
	gateway=$GATEWAY
else
	echo "Informe o gateway"
	read gateway
fi

echo "IP = $ip"
echo "Mascara de rede: $mask"
echo "Placa: $placa"
echo "Canal: $canal"
echo "Nome da rede: $nome"
echo "Gateway: $gateway"

#esse código desativa a busca por redes
service network-manager stop

#esse codigo torna a interface desativada
ip link set $placa down

#Aqui termina a preparação para a configuração da rede.
#Vamos começar a configurar

iwconfig $placa mode ad-hoc
iwconfig $placa essid $nome
iwconfig $placa channel $canal
iwconfig $placa key off

#Terminamos a configuração. Falta ativar a rede:

ip link set $placa up

ip addr add $ip/$mask dev $placa

#Pronto! A rede foi configurada

#Vamos adicionar o gateway padrao para o forward.

route add default gw $gateway

#Pronto!!