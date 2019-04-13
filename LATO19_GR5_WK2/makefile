CXX = g++
CXXFLAGS = -g -pedantic -Wall

PlikWykonywalny = test
MAIN = OperatoryBitowe
Lib01 = BitArray

#linkowanie ktore wykonuje sie na koncu
$(PlikWykonywalny): $(MAIN).o $(Lib01).o
	$(CXX) $(CXXFLAGS) $^ -o $@
#wszystko na prawo, wszystko na lewo

$(MAIN).o: $(MAIN).cpp $(Lib01).o
#samo sie uzupelnia

$(Lib01).o: $(Lib01).cpp $(Lib01).h


.PHONY: clean run

clean:
	rm -rf *.o $(PlikWykonywalny)

run:
	./$(PlikWykonywalny)




	