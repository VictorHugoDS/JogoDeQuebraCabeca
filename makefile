CXX = g++
CPPFLAGS = -Wall -g
OBJFILES = tabuleiro.o interface_matriz.o interface_arvore.o interface_busca_profundidade.o largura/busca_largura.o main.o

# Arquivos da busca em largura
LARGFILES = largura/busca_largura.o main.o #largura-files
LARGTARGET = larg #largura-target
LARGRM = clean-larg #largura-remove

# Arquivos do tabuleiro
TABFILES = tabuleiro.o main.o
TABTARGET = tab
TABRM = clean-tab

# Tabuleiro + Árvore + busca em largura
TABLFILES = tabuleiro.o arvore.o largura/busca_largura.o main.o
TABLTARGET = tabl
TABLRM = clean-tabl

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


$(TABTARGET): $(TABFILES)
	$(CXX) $(CPPFLAGS) -o $(TABTARGET) $(TABFILES)

$(TABRM):
	rm $(TABFILES) $(TABTARGET)

$(TABLTARGET): $(TABLFILES)
	$(CXX) $(CPPFLAGS) -o $(TABLTARGET) $(TABLFILES)

$(TABLRM):
	rm $(TABLFILES) $(TABLTARGET)
