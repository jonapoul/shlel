CC      = gcc
CCFLAGS = -c $(LDFLAGS)
LD      = $(CC) $(LDFLAGS)
LDFLAGS = -Wall

ROOTDIR := .
OBJDIR  := obj
BINDIR  := bin
SRCDIR  := src
INCDIR  := inc

INC  := -I$(ROOTDIR) -I$(INCDIR)
SRC  := $(wildcard $(SRCDIR)/*.c)
OBJ  := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
EXEC := shlel

all: $(EXEC)

$(EXEC): $(OBJ) | dir
	$(LD) -o $(BINDIR)/$@ $(OBJ)

dir:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

clean:
	rm -f $(OBJDIR)/* 2>/dev/null || true
	rm -f $(BINDIR)/* 2>/dev/null || true

diff:
	git diff --stat

rebuild: clean $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | dir
	$(CC) $(CCFLAGS) $(INC) -c $< -o $@
