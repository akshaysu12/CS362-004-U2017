cmake_minimum_required(VERSION 3.6)
project(domLion)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES dominion.c dominion.h interface.c playdom.c player.c rngs.c rt.c)
add_executable(domLion ${SOURCE_FILES})

set(PLAYDOM dominion.c playdom.c rngs.c)
add_executable(play ${PLAYDOM})

set(PLAYER dominion.c player.c interface.c rngs.c)
add_executable(player ${PLAYER})

set(TESTER dominion.c smithyTestAS.c rngs.c)
add_executable(TESTER ${TESTER})