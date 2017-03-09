
all:
	g++ oscillatore/oscillatore.cpp
	g++ integratore/integratore.cpp
osc:
	g++ oscillatore/oscillatore.cpp
int:
	g++ integratore/integratore.cpp
clean:
	rm *.out
