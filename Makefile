# コンパイラとフラグ
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ソースとオブジェクトファイル
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# 実行ファイル名
EXEC = bsq

# デフォルトターゲット
all: $(EXEC)

# 実行ファイルの生成
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# オブジェクトファイルの生成
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# オブジェクトファイルの削除
clean:
	rm -f $(OBJ)

# オブジェクトファイルと実行ファイルの削除
fclean: clean
	rm -f $(EXEC)

# fcleanターゲットの後にallターゲットを実行
re: fclean all

.PHONY: all clean fclean re
