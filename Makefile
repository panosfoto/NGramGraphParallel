SOURCES_FOLDER		= src
HEADERS_FOLDER		= include
TEMPLATES_FOLDER	= include/templateImp
OBJECTS				= $(SOURCES_FOLDER)/main.o $(SOURCES_FOLDER)/GraphSimilarity.o $(SOURCES_FOLDER)/NGramGraph.o $(SOURCES_FOLDER)/StringAtom.o $(SOURCES_FOLDER)/StringPayload.o $(SOURCES_FOLDER)/StringSplitter.o
OUT					= main
CC					= g++
FLAGS				= -c -std=c++11 -Wall -I$(HEADERS_FOLDER) 

all: $(OUT)

$(OUT): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

$(SOURCES_FOLDER)/main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

$(SOURCES_FOLDER)/GraphSimilarity.o: $(SOURCES_FOLDER)/GraphSimilarity.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/GraphSimilarity.cpp

$(SOURCES_FOLDER)/NGramGraph.o: $(SOURCES_FOLDER)/NGramGraph.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/NGramGraph.cpp

$(SOURCES_FOLDER)/StringAtom.o: $(SOURCES_FOLDER)/StringAtom.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/StringAtom.cpp

$(SOURCES_FOLDER)/StringPayload.o: $(SOURCES_FOLDER)/StringPayload.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/StringPayload.cpp

$(SOURCES_FOLDER)/StringSplitter.o: $(SOURCES_FOLDER)/StringSplitter.cpp
	$(CC) $(FLAGS) $(SOURCES_FOLDER)/StringSplitter.cpp

clean:
	rm -f $(OBJECTS) $(OUT)

no_exe_clean:
	rm -f $(OBJECTS)

count:
	wc -l $(SOURCES_FOLDER)/*.cpp $(HEADERS_FOLDER)/*.hpp $(TEMPLATES_FOLDER)/*.tcc