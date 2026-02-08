CC = clang

SRCS = filter.c helpers.c
TARGET = filter

CFLAGS = -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow 
LDLIBS = -lm 

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $(TARGET) $(SRCS)
