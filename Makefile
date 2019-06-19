CFLAGS += -std=c++11

SUBDIRS = debug coding

all: $(addsuffix .build,$(SUBDIRS))

clean: $(addsuffix .clean,$(SUBDIRS)) clean.local

clean.local: force
	rm -rf .*.swp mk.log core

%.build: force
	$(MAKE) -C $(basename $@)

%.clean: force
	$(MAKE) -C $(basename $@) clean

force:
