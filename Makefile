XENO_CONFIG := /usr/bin/xeno-config

CFLAGS := `$(XENO_CONFIG) --posix --alchemy --cflags`
LDFLAGS := $(shell $(XENO_CONFIG) --posix --alchemy --ldflags)

CC := gcc   
EXECUTABLE := helloWorld

all: $(EXECUTABLE)

%: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean: 
	rm -f $(EXECUTABLE)

