CC=g++
CFLAGS=-g
OBJECTS=main.o ds_string.o

run: app
	./app

app: $(OBJECTS)
	$(CC) $(CFLAGS) -o app $(OBJECTS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

ds_string.o: ds_string.cpp
	$(CC) $(CFLAGS) -c ds_string.cpp

ds_list.o: ds_list.cpp
	$(CC) $(CFLAGS) -c ds_list.cpp

clean:
	rm -rf *.o app
