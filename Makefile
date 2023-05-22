CC=g++

app: main.o ds_string.o ds_list.o
	$(CC) -o app main.o ds_string.o ds_list.o

main.o: main.cpp
	$(CC) -c main.cpp

ds_string.o: ds_string.cpp
	$(CC) -c ds_string.cpp

ds_list.o: ds_list.cpp
	$(CC) -c ds_list.cpp

clean:
	rm -rf *.o app
