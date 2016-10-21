compile: main.c linked_list.c linked_list.h library.c library.h
	gcc main.c linked_list.c library.c -o app

clean: 
	rm *~

run: compile
	./app
