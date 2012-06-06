#
#
#

OBJ = main 
CommonHeader = config.h utility.h constants.h

all: $(OBJ)
	
main: httpd.o utility.o request.o response.o general.o entity.o thread_pool.o

httpd.o: httpd.h $(CommonHeader)

request.o: request.h response.h $(CommonHeader)
response.o: response.h request.h $(CommonHeader)
general.o: general.h $(CommonHeader)
entity.o: entity.h $(CommonHeader)
thread_pool.o: thread_pool.h $(CommonHeader)

utility.o: $(CommonHeader)

clean:
	rm *.o
	rm $(OBJ)
