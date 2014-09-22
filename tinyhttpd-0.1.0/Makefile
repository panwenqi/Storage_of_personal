all: httpd

httpd: httpd.c
#	gcc -W -Wall -lsocket -lpthread -o httpd httpd.c
	gcc -W -Wall httpd.c -g -o httpd -lpthread
client:
	gcc simpleclient.c -g -o client
clean:
	rm httpd client
