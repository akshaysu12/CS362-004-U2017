CFLAGS = -Wall -fpic -coverage -lm

randTests: randomcardtest1 randomcardtest2 randomtestadventurer
	./randomcardtest1 &> randomtestcard1.out
	gcov -b -c dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

	./randomcardtest2 &> randomtestcard2.out
	gcov -b -c dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

	./randomtestadventurer &> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomcardtest2: randomcardtest2.c dominion.o rngs.o
	gcc -o randomcardtest2 randomcardtest2.c -g dominion.o rngs.o $(CFLAGS)

randomcardtest1: randomcardtest1.c dominion.o rngs.o
	gcc -o randomcardtest1 randomcardtest1.c -g dominion.o rngs.o $(CFLAGS)

unitTests: smithyCardTest adventurerCardTest CouncilRoomCardTest baronCardTest testIsGameOver testGainCard drawCardTest testEndTurn
	./smithyCardTest &> unittestresult.out
	./adventurerCardTest >> unittestresult.out
	./CouncilRoomCardTest >> unittestresult.out
	./baronCardTest >> unittestresult.out
	./testIsGameOver >> unittestresult.out
	./testGainCard >> unittestresult.out
	./testEndTurn >> unittestresult.out
	./drawCardTest >> unittestresult.out
	gcov -b -c dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

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

all: playdom player randTests

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
