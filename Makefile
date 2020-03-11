CC = gcc
CFLAGS = -std=c11 -Wall -Werror
src_files = src/main.c src/evaluator.c src/linked_list.c src/parser.ca src/scanner.c src/memory.c
obj_files = main.o evaluator.o linked_List.o parser.o scanner.o memory.o
app = beval

.PHONY: all
all: $(obj_files)
	$(CC) $(CFLAGS) -o $(app) $^

$(filter %.o, $(obj_files)): %.o: src/%.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf $(app) $(obj_files) core *.core

