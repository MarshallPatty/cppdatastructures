CC=g++

app: main.o ds_string.o
	$(CC) -o app main.o ds_string.o

main.o: main.cpp
	$(CC) -c main.cpp

ds_string.o: ds_string.cpp
	$(CC) -c ds_string.cpp

clean:
	rm -rf *.o app
