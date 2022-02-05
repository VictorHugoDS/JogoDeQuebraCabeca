# Jogo de Quebra-cabeças de 8 Peças

Alunos: Henrique de Oliveira Peixoto e Victor Hugo Duarte da Silva

## Build

Para compilar o projeto é necessário gerar os object files (.o) dos headers incluídos em main, excetuando os arquivos incluídos como cpp.

Se possuir o make instalado, pode compilar digitando o seguinte no terminal:

```
make
```

Se o make não estiver disponível na máquina, será necessário inserir todos os comandos abaixo (pode fazer isso por meio de um script). Isso vai gerar os arquivos de objeto necessários para a compilação.

```
g++  -Wall -g  -c -o tabuleiro.o tabuleiro.cpp
g++  -Wall -g  -c -o arvore.o arvore.cpp
g++  -Wall -g  -c -o largura/busca_largura.o largura/busca_largura.cpp
g++  -Wall -g  -c -o main.o main.cpp
g++ -Wall -g -o main tabuleiro.o arvore.o largura/busca_largura.o main.o
```

## Flags do Compilador

### Otimização
Caso queira passar uma flag de otimização para o compilador, substitua `-g` por `-O3` ou ainda `-Ofast` (agressivo). Pode ser útil para acelerar as buscas

### Avisos do compilador
Se quiser omitir os avisos, remova a flag `-Wall`

### Depuração
`-g`: Habilita a depuração. Incompatível com as flags de otimização.

# Instruções

Execute com: `./main` (Linux) ou `main.exe` (Windows) no terminal ou clique duas vezes no executável após a compilação.

Selecione o método de busca desejado e siga as instruções na tela para configurar a busca.

Métodos de busca disponíveis:

* Busca em Profundidade
* Busca em Largura
