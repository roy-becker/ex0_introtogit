CC = gcc
OBJS = RLEList.o AsciiArtTool.o
EXEC = AsciiArtTool
DEBUG = # now empty, assign -g for debug
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@

AsciiArtTool.o : tool/AsciiArtTool.c tool/AsciiArtTool.h RLEList.h
RLEList.o : RLEList.c RLEList.h
main.o : tool/main.c tool/AsciiArtTool.h RLEList.h

clean:
	rm -f $(OBJS) $(EXEC)
