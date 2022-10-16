CFLAGS = -O3

TESTS = test00 test01 test02 test03 test04 test05 test06 test07 test08 test09
TESTS+= test10 test11 test12 test13 test14 test15 test16 test17 test18 test19
TESTS+= test20 test21 test22 test23 test24 test25 test26 test27 test28

TEST_OBJS = $(addsuffix .o, $(TESTS))

TEST_TARGETS = $(addprefix run-, $(TESTS))

.PHONY: all test clean $(TEST_TARGETS)

all: $(TESTS)

test: $(TEST_TARGETS)

clean:
	$(RM) $(TESTS) $(TEST_OBJS)

$(TEST_TARGETS): run-test%: test%
	(./$<; echo $$?) | diff -u ref$*.txt -

$(TESTS): %: %.o

$(TEST_OBJS): try.h
