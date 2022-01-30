CC = g++
CPPFLAGS = -Wall -g
OBJFILES = interface_matriz.o interface_arvore.o interface_busca_profundidade.o largura/busca_largura.o main.o

# Arquivos da busca em largura
LARGFILES = largura/busca_largura.o main.o
LARGTARGET = larg
LARGRM = clean-larg

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)

$(LARGTARGET): $(LARGFILES)
	$(CC) $(CPPFLAGS) -o $(LARGTARGET) $(LARGFILES)

$(LARGRM):
	rm $(LARGFILES) $(LARGTARGET)
