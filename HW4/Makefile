CFLAGS = -Wall -fsanitize=address,leak

TrieTest : TrieTest.o Trie.o
	g++ $(CFLAGS) -o TrieTest TrieTest.o Trie.o

TrieTest.o : TrieTest.cpp Trie.h
	g++ $(CFLAGS) -c TrieTest.cpp

Trie.o : Trie.cpp Trie.h
	g++ $(CFLAGS) -c Trie.cpp

clean : 
	rm -f *.o