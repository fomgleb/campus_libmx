BINARYNAME = libmx.a

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -gdwarf-4

OBJDIR = obj
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(addprefix $(OBJDIR)/,$(notdir $(SOURCES:.c=.o)))

all: $(BINARYNAME)

$(BINARYNAME): $(OBJDIR) $(SOURCES) $(OBJECTS)
	ar cr $(BINARYNAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

uninstall: clean
	rm -rf $(BINARYNAME)

clean:
	rm -rf $(OBJDIR)

reinstall: uninstall all


