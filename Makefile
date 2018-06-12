SOURCES_FOLDER		= src
HEADERS_FOLDER		= include
TEMPLATES_FOLDER	= include/templateImp
OBJECTS				= $(SOURCES_FOLDER)/test.o $(SOURCES_FOLDER)/GraphSimilarity.o $(SOURCES_FOLDER)/NGramGraph.o $(SOURCES_FOLDER)/StringAtom.o $(SOURCES_FOLDER)/StringPayload.o $(SOURCES_FOLDER)/StringSplitter.o
OUT					= test
CC					= g++
FLAGS				= -c -std=c++11 -Wall -I$(HEADERS_FOLDER) 

all: $(OUT)

$(OUT): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

$(SOURCES_FOLDER)/test.o: test.cpp
	$(CC) $(FLAGS) test.cpp -o $@

$(SOURCES_FOLDER)/GraphSimilarity.o: $(SOURCES_FOLDER)/GraphSimilarity.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/GraphSimilarity.cpp -o $@

$(SOURCES_FOLDER)/NGramGraph.o: $(SOURCES_FOLDER)/NGramGraph.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/NGramGraph.cpp -o $@

$(SOURCES_FOLDER)/StringAtom.o: $(SOURCES_FOLDER)/StringAtom.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/StringAtom.cpp -o $@

$(SOURCES_FOLDER)/StringPayload.o: $(SOURCES_FOLDER)/StringPayload.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/StringPayload.cpp -o $@

$(SOURCES_FOLDER)/StringSplitter.o: $(SOURCES_FOLDER)/StringSplitter.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/StringSplitter.cpp -o $@

clean:
	rm -f $(OBJECTS) $(OUT)

no_exe_clean:
	rm -f $(OBJECTS)

count:
	wc -l $(SOURCES_FOLDER)/*.cpp $(HEADERS_FOLDER)/*.hpp $(TEMPLATES_FOLDER)/*.tcc
