CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BINDIR = bin

TARGET = $(BINDIR)/plugin_host
PLUGIN = $(BINDIR)/plugin.so

all: $(TARGET) $(PLUGIN)

$(TARGET): $(OBJDIR)/host.o
	@mkdir -p $(BINDIR)
	$(CC) $< -o $@ $(LDFLAGS)

$(PLUGIN): $(SRCDIR)/plugin.c
	@mkdir -p $(BINDIR)
	$(CC) -shared -fPIC $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all run clean
