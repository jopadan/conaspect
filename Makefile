PROGRAM=conaspect
GCC ?= gcc
INSTALL ?= install
RM ?= rm
PREFIX ?= /usr/local
BINDIR ?= bin
CFLAGS ?= -march=native -O2 -pipe

ifdef _WIN32
OBJECT_EXT ?= .obj
EXECUTABLE_EXT ?= .exe
else
OBJECT_EXT ?= .o
EXECUTABLE_EXT ?= 
endif

all: $(PROGRAM)

$(PROGRAM): $(PROGRAM)$(OBJECT_EXT)
	$(GCC) $(CFLAGS) -lm -o $(PROGRAM) $(PROGRAM)$(OBJECT_EXT)

$(PROGRAM)$(OBJECT_EXT): $(PROGRAM).c
	$(GCC) $(CFLAGS) -c $(PROGRAM).c
clean:
	$(RM) -rf $(PROGRAM)$(OBJECT_EXT) $(PROGRAM)$(EXECUTABLE_EXT)

install: $(PROGRAM)
	$(INSTALL) -d $(PREFIX)/$(BINDIR)
	$(INSTALL) -m 755 $(PROGRAM)$(EXECUTABLE_EXT) $(PREFIX)/$(BINDIR)

uninstall: $(PROGRAM)
	$(RM) -rf $(PREFIX)/$(BINDIR)/$(PROGRAM)$(EXECUTABLE_EXT)
