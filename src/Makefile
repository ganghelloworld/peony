#
#
#

OBJ = main 

all: $(OBJ)
	
main: httpd.o utility.o
httpd.o: httpd.h utility.h config.h
utility.o: utility.h

clean:
	rm *.o
	rm $(OBJ)
