compile: myTunez.c
	gcc myTunez.c -o myTunez

clean: 
	rm *~

run: myTunez
	./myTunez
