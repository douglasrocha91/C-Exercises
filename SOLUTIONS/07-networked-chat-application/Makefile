CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BINDIR = bin

TARGET_SERVER = $(BINDIR)/chat_server
TARGET_CLIENT = $(BINDIR)/chat_client

all: $(TARGET_SERVER) $(TARGET_CLIENT)

$(TARGET_SERVER): $(OBJDIR)/server.o
	@mkdir -p $(BINDIR)
	$(CC) $< -o $@ $(LDFLAGS)

$(TARGET_CLIENT): $(OBJDIR)/client.o
	@mkdir -p $(BINDIR)
	$(CC) $< -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run-server: $(TARGET_SERVER)
	./$(TARGET_SERVER)

run-client: $(TARGET_CLIENT)
	./$(TARGET_CLIENT)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean run-server run-client
