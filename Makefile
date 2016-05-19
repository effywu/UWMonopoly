CXX=g++
CXXFLAGS= -Wall -DDEBUG
OBJECTS=main.o controller.o TextDisplay.o View.o gamenotification.o game.o player.o NeedlesCard.o SLCCard.o nonproperty.o residence.o gym.o academicbuilding.o building.o square.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=bb7k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.o bb7k
.PHONY: clean
