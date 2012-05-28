#
#
#

OBJ = main 
CommonHeader = config.h utility.h constants.h

all: $(OBJ)
	
main: httpd.o utility.o request.o general.o

httpd.o: httpd.h $(CommonHeader)

request.o: request.h $(CommonHeader)
response.o: response.h $(CommonHeader)
general.o: general.h $(CommonHeader)

utility.o: utility.h

clean:
	rm *.o
	rm $(OBJ)
