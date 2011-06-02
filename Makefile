LIB_NAME=bare
STATICLIB_NAME=lib${LIB_NAME}.a

CFLAGS=-g -O3 -Wall -I${LIB_NAME} -I${LIB_NAME}/src ${OPTS}

SRC=$(wildcard ${LIB_NAME}/src/*.c)
OBJ=$(patsubst %.c,%.o,${SRC})

LIB_OBJ=${OBJ}

TEST_SRC=$(wildcard test/*_test.c)
TESTS=$(patsubst %.c,%,${TEST_SRC})

TEST_HELPER_SRC=$(wildcard test/helpers/*.c)
TEST_HELPER_OBJ=$(patsubst %.c,%.o,${TEST_HELPER_SRC})


all: clean ${STATICLIB_NAME} $(TESTS)
debug: CFLAGS+=-DLOGGER_ERROR
debug: all

${STATICLIB_NAME}: ${LIB_OBJ}
	ar rvs $@ ${LIB_OBJ}
	ranlib $@


clean:
	rm -rf ${STATICLIB_NAME}
	rm -rf ${OBJ}
	rm -rf ${TEST_HELPER_OBJ}
	rm -rf ${TESTS}
	rm -rf test/*.dSYM
	rm -rf tmp/*

${TESTS}: %: %.c ${STATICLIB_NAME} ${TEST_HELPER_OBJ}
	$(CC) $(CFLAGS) -Itest -o $@ $< ${STATICLIB_NAME} ${TEST_HELPER_OBJ}

tests: all ${TESTS}
	sh test/runtests.sh

memcheck: all ${TESTS}
	valgrind --leak-check=full --show-reachable=no ./test/functional_test