CXX = g++
CXXFLAGS = -g -pedantic -Wall

PlikWykonywalny = stest
MAIN = Figury
Lib01 = Kwadrat
Lib02 = Kolo
Lib03 = Trojkat
#linkowanie ktore wykonuje sie na koncu
$(PlikWykonywalny): $(MAIN).o 
	$(CXX) $(CXXFLAGS) $^ -o $@
#wszystko na prawo, wszystko na lewo

$(MAIN).o: $(MAIN).cpp $(Lib01).h $(Lib02).h $(Lib03).h
#samo sie uzupelnia


.PHONY: clean run

clean:
	rm -rf *.o $(PlikWykonywalny)

run:
	./$(PlikWykonywalny)




	