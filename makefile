CXX = g++
CPPFLAGS = -Wall -g
OBJFILES = interface_matriz.o interface_arvore.o interface_busca_profundidade.o largura/busca_largura.o main.o

# Arquivos da busca em largura
LARGFILES = largura/busca_largura.o main.o #largura-files
LARGTARGET = larg #largura-target
LARGRM = clean-larg #largura-remove

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)

$(LARGTARGET): $(LARGFILES)
	$(CXX) $(CPPFLAGS) -o $(LARGTARGET) $(LARGFILES)

$(LARGRM):
	rm $(LARGFILES) $(LARGTARGET)
