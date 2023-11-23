# Especifica o compilador a ser usado
CC = gcc

# Flags de compilação
CFLAGS = -g

# Lista dos arquivos-fonte
SOURCES = main.c funcs.c lex.c parse_tree.c parser.tab.c globals.c 

# Nome do arquivo de saída
OUTPUT = lexer

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	rm -f $(OUTPUT)

.PHONY: all clean
