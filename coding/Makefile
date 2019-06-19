CFLAGS += -std=c++11

TARGETS += callbacks
TARGETS += frequency
TARGETS += histogram
TARGETS += pipeline
TARGETS += track

CFLAGS   += -g
CPPFLAGS += $(CFLAGS)
LDLIBS   += -lpthread

all: $(TARGETS)

clean: force
	rm -rf $(TARGETS) $(addsuffix .o,$(TARGETS)) .*.swp mk.log core

force:
