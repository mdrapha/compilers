# Especifica o compilador a ser usado
CC = gcc

# Flags de compilação
CFLAGS = -g 

# Lista dos arquivos-fonte
SOURCES = src/main.c src/funcs.c src/lex.c src/parse_tree.c src/parser.tab.c src/globals.c src/symbTable.c

# Nome do arquivo de saída
OUTPUT = bin/gcm

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	rm -f $(OUTPUT)

.PHONY: all clean
