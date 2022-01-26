CC = g++
CPPFLAGS = -Wall -g
OBJFILES = interface_matriz.o interface_arvore.o interface_busca_profundidade.o main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
