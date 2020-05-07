INC=../cpp-httplib/ ../json/include
INC_PARAMS=$(foreach d, $(INC), -I$d)
CC=clang++
CFLAGS=-shared $(INC_PARAMS) -stdlib=libstdc++ -std=c++14 -fPIC

FILES=X4RestServer/src/somain.cpp X4RestServer/src/ffi/FFIInvoke.cpp X4RestServer/src/httpserver/HttpServer.cpp

OUTFILE=X4RestServer.so

make:
	$(CC) $(CFLAGS) $(FILES) -o $(OUTFILE)

clean:
	rm -f $(OUTFILE)