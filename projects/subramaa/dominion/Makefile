CFLAGS = -Wall -fpic -coverage -lm

testIsGameOver: testIsGameOver.c dominion.o rngs.o
	gcc -o testIsGameOver -g  testIsGameOver.c dominion.o rngs.o $(CFLAGS)

testGainCard: testGainCard.c dominion.o rngs.o
	gcc -o testGainCard -g  testGainCard.c dominion.o rngs.o $(CFLAGS)

drawCardTest: drawCardTest.c dominion.o rngs.o
	gcc -o drawCardTest -g  drawCardTest.c dominion.o rngs.o $(CFLAGS)

testEndTurn: testEndTurn.c dominion.o rngs.o
	gcc -o testEndTurn -g  testEndTurn.c dominion.o rngs.o $(CFLAGS)

smithyCardTest: smithyCardTest.c dominion.o rngs.o
	gcc -o smithyCardTest -g  smithyCardTest.c dominion.o rngs.o $(CFLAGS)

adventurerCardTest: adventurerCardTest.c dominion.o rngs.o
	gcc -o adventurerCardTest -g  adventurerCardTest.c dominion.o rngs.o $(CFLAGS)

CouncilRoomCardTest: CouncilRoomCardTest.c dominion.o rngs.o
	gcc -o CouncilRoomCardTest -g  CouncilRoomCardTest.c dominion.o rngs.o $(CFLAGS)

baronCardTest: baronCardTest.c dominion.o rngs.o
	gcc -o baronCardTest -g  baronCardTest.c dominion.o rngs.o $(CFLAGS)

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard smithyCardTest adventurerCardTest CouncilRoomCardTest baronCardTest testEndTurn drawCardTest testGainCard testIsGameOver

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
