CC = gcc
OBJS = RLEList.o AsciiArtTool.o
EXEC = AsciiArtTool
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@

AsciiArtTool.o : tool/AsciiArtTool.c tool/AsciiArtTool.h RLEList.h
RLEList.o : RLEList.c RLEList.h
main.o : tool/main.c tool/AsciiArtTool.h RLEList.h

clean:
	rm -f $(OBJS) $(EXEC)
