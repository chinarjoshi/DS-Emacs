all:data.o structures.o hash.o trie.o
		g++ -o data data.o structures.o hash.o trie.o
clean:
		$(RM) data