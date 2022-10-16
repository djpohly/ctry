CFLAGS = -O3 -I.

TESTS = $(addprefix test, 00 01 02 03 04 05 06 07 08 09 \
                          10 11 12 13 14 15 16 17 18 19 \
                          20 21 22 23 24 25 26 27)

TEST_BINS = $(addprefix test/, $(TESTS))
TEST_OBJS = $(addsuffix .o, $(TEST_BINS))

.PHONY: test clean $(TEST)

test: $(TESTS)

clean:
	$(RM) $(TEST_BINS) $(TEST_OBJS)

$(TESTS): test%: test/test%
	(./$<; echo $$?) | diff -u test/ref$*.txt -

$(TEST_BINS): %: %.o

$(TEST_OBJS): try.h
