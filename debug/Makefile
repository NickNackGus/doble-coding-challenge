CFLAGS += -std=c++11

TARGETS += problem1
TARGETS += problem2
TARGETS += problem3
TARGETS += problem4
TARGETS += problem5

CFLAGS   += -g
CPPFLAGS += $(CFLAGS)
LDLIBS   += -lpthread

all: $(TARGETS)

clean: force
	rm -rf $(TARGETS) $(addsuffix .o,$(TARGETS)) .*.swp mk.log core

force:
