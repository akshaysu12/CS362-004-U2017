CFLAGS = -Wall -fpic -fprofile-arcs -ftest-coverage -lm

smithyTestAS: smithyTestAS.c dominion.o rngs.o
	gcc -o smithyTestAS smithyTestAS.c -g dominion.o rngs.o  $(CFLAGS)

adventurerTestAS: dominion.o rngs.o
	gcc -o adventurerTestAS adventurerTestAS.c -g dominion.o rngs.o  $(CFLAGS)

baronTestAS: dominion.o rngs.o
	gcc -o baronTestAS baronTestAS.c -g dominion.o rngs.o  $(CFLAGS)

council_roomTestAS: dominion.o rngs.o
	gcc -o council_roomTestAS council_roomTestAS.c -g dominion.o rngs.o  $(CFLAGS)

testDrawCard1AS: dominion.o rngs.o
	gcc -o testDrawCard1AS testDrawCard1AS.c -g dominion.o rngs.o  $(CFLAGS)

testEndTurnAS: dominion.o rngs.o
	gcc -o testEndTurnAS testEndTurnAS.c -g dominion.o rngs.o  $(CFLAGS)

testGainCardAS: dominion.o rngs.o
	gcc -o testGainCardAS testGainCardAS.c -g dominion.o rngs.o  $(CFLAGS)

testIsGameOverAS: dominion.o rngs.o
	gcc -o testIsGameOverAS testIsGameOverAS.c -g dominion.o rngs.o  $(CFLAGS)

randomtestadventurerAS: dominion.o rngs.o randomtestadventurerAS.c
	gcc -o randomtestadventurerAS randomtestadventurerAS.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestadventurerAS &> randomtestadventurerAS.out
	gcov -b dominion.c >> randomtestadventurerAS.out
	cat dominion.c.gcov >> randomtestadventurerAS.out

randomcardtest1AS: dominion.o rngs.o
	gcc -o randomcardtest1AS randomcardtest1AS.c -g dominion.o rngs.o $(CFLAGS)
	./randomcardtest1AS &> randomcardtest1AS.out
	gcov -b dominion.c >> randomcardtest1AS.out
	cat dominion.c.gcov >> randomcardtest1AS.out

randomcardtest2AS: dominion.o rngs.o
	gcc -o randomcardtest2AS randomcardtest2AS.c -g dominion.o rngs.o $(CFLAGS)
	./randomcardtest2AS &> randomcardtest2AS.out
	gcov -b dominion.c >> randomcardtest2AS.out
	cat dominion.c.gcov >> randomcardtest2AS.out

akshayRandTests: randomtestadventurerAS randomcardtest1AS randomcardtest2AS

runASunittests: smithyTestAS adventurerTestAS baronTestAS council_roomTestAS testDrawCard1AS testEndTurnAS testGainCardAS testIsGameOverAS
	./smithyTestAS &> ASunittests.out
	./adventurerTestAS &> ASunittests.out
	./baronTestAS &> ASunittests.out
	./council_roomTestAS &> ASunittests.out
	./testDrawCard1AS &> ASunittests.out
	./testEndTurnAS &> ASunittests.out
	./testGainCardAS &> ASunittests.out
	./testIsGameOverAS &> ASunittests.out
	gcov -b dominion.c >> ASunittests.out
	cat dominion.c.gcov >> ASunittests.out

akshayTests: akshayRandTests runASunittests

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

testhelper.o: dominion.o
	gcc -c testhelper.c -g $(CFLAGS)

unittest1: dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: testhelper.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o testhelper.o $(CFLAGS)

cardtest2: dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: testhelper.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o testhelper.o $(CFLAGS)

cardtest4: testhelper.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o testhelper.o $(CFLAGS)

rununittests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 &> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -d -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randtesthelper.o: dominion.o
	gcc -c randtesthelper.c -g $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe badTestDrawCard badTestDrawCard.exe randomtestadventurer randtestcard1 randtestcard2 smithyTestAS unittest2 unittest3 unittest4 runPlaydom cardtest1 cardtest2 cardtest3 cardtest4
