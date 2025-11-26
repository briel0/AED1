# Nome do compilador
CXX = gcc
# Flags de compilação (opcional)
CXXFLAGS = -Wall -Wextra -O2

# Nome do executável
TARGET = programa

# Arquivos-fonte
SRC = main.c lista.c estudante.c

# Regra padrão
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

