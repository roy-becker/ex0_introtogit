CC = gcc
OBJS = RLEList.o AsciiArtTool.o main.o
EXEC = AsciiArtTool
DEBUG = # now empty, assign -g for debug
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@

AsciiArtTool.o : tool/AsciiArtTool.c tool/AsciiArtTool.h tool/../RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) tool/AsciiArtTool.c
RLEList.o : RLEList.c RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) RLEList.c
main.o : tool/main.c tool/AsciiArtTool.h tool/../RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) tool/main.c

clean:
	rm -f $(OBJS) $(EXEC)
