
all:
	g++ integratore/src/integratore.cpp -o integratore/bin/integratore
	g++ oscillatore/src/oscillatore.cpp -o oscillatore/bin/integratore
osc:
	g++ oscillatore/src/oscillatore.cpp -o oscillatore/bin/integratore
int:
	g++ integratore/src/integratore.cpp -o integratore/bin/integratore
clean:
	rm */bin/*
