CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lm
SOURCES=ftp.c ftpcmd.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ftp

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *.o ftp
