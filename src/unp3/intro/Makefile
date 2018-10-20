all:
	gcc -o daytimetcpcli_v4 daytimetcpcli_v4.c
	gcc -o daytimetcpsrv_v4 daytimetcpsrv_v4.c
	gcc -o daytimetcpcli_v6 daytimetcpcli_v6.c
	gcc -o daytimetcpsrv_v6 daytimetcpsrv_v6.c
	gcc -o byteorder byteorder.c
	gcc -o htons_ntohs htons_ntohs.c
	gcc -o inet_aton-inet_ntoa inet_aton-inet_ntoa.c
	gcc -o inet_pton-inet_ntop inet_pton-inet_ntop.c
	gcc -o hello_socket hello_socket.c
	gcc -o hello_connect hello_connect.c
	gcc -o hello_bind_listen_accept hello_bind_listen_accept.c


clean:
	rm -rf daytimetcpcli_v4 daytimetcpsrv_v4 daytimetcpcli_v6 \
		daytimetcpsrv_v6 byteorder htons_ntohs \
		inet_aton-inet_ntoa inet_pton-inet_ntop \
		hello_socket hello_connect hello_bind_listen_accept