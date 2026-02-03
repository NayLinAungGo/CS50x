CC = gcc
CFLAGS = -g -Wall -Wextra
LIBS = -lcs50

ARGS = Alice Bob Charlie

# Preferences that creates a perfect loop
#run: tideman
#	@expect -c ' \
#		spawn ./tideman ${ARGS}; \
#		expect "Number of voters: " { send "3\r" }; \
#		expect "Rank 1:" { send "Alice\r" }; \
#		expect "Rank 2:" { send "Bob\r" }; \
#		expect "Rank 3:" { send "Charlie\r" }; \
#		\
#		expect "Rank 1:" { send "Bob\r" }; \
#		expect "Rank 2:" { send "Charlie\r" }; \
#		expect "Rank 3:" { send "Alice\r" }; \
#		\
#		expect "Rank 1:" { send "Charlie\r" }; \
#		expect "Rank 2:" { send "Alice\r" }; \
#		expect "Rank 3:" { send "Bob\r" }; \
#		\
#		interact'

# Preferences table from Walkthrough YouTube video at 8:00
run: tideman
	@expect -c ' \
		spawn ./tideman ${ARGS}; \
		expect "Number of voters: " { send "9\r" }; \
		expect "Rank 1:" { send "Alice\r" }; \
		expect "Rank 2:" { send "Bob\r" }; \
		expect "Rank 3:" { send "Charlie\r" }; \
		\
		expect "Rank 1:" { send "Alice\r" }; \
		expect "Rank 2:" { send "Bob\r" }; \
		expect "Rank 3:" { send "Charlie\r" }; \
		\
		expect "Rank 1:" { send "Alice\r" }; \
		expect "Rank 2:" { send "Bob\r" }; \
		expect "Rank 3:" { send "Charlie\r" }; \
		\
		expect "Rank 1:" { send "Bob\r" }; \
		expect "Rank 2:" { send "Charlie\r" }; \
		expect "Rank 3:" { send "Alice\r" }; \
		\
		expect "Rank 1:" { send "Bob\r" }; \
		expect "Rank 2:" { send "Charlie\r" }; \
		expect "Rank 3:" { send "Alice\r" }; \
		\
		\
		expect "Rank 1:" { send "Charlie\r" }; \
		expect "Rank 2:" { send "Alice\r" }; \
		expect "Rank 3:" { send "Bob\r" }; \
		\
		expect "Rank 1:" { send "Charlie\r" }; \
		expect "Rank 2:" { send "Alice\r" }; \
		expect "Rank 3:" { send "Bob\r" }; \
		\
		expect "Rank 1:" { send "Charlie\r" }; \
		expect "Rank 2:" { send "Alice\r" }; \
		expect "Rank 3:" { send "Bob\r" }; \
		\
		expect "Rank 1:" { send "Charlie\r" }; \
		expect "Rank 2:" { send "Alice\r" }; \
		expect "Rank 3:" { send "Bob\r" }; \
		interact'

# Preferences table from Walkthrough YouTube video at 8:00
#run: tideman
#	@expect -c ' \
#		spawn ./tideman ${ARGS}; \
#		expect "Number of voters: " { send "4\r" }; \
#		expect "Rank 1:" { send "Alice\r" }; \
#		expect "Rank 2:" { send "Charlie\r" }; \
#		expect "Rank 3:" { send "Bob\r" }; \
#		\
#		expect "Rank 1:" { send "Alice\r" }; \
#		expect "Rank 2:" { send "Charlie\r" }; \
#		expect "Rank 3:" { send "Bob\r" }; \
#		\
#		expect "Rank 1:" { send "Charlie\r" }; \
#		expect "Rank 2:" { send "Alice\r" }; \
#		expect "Rank 3:" { send "Bob\r" }; \
#		\
#		expect "Rank 1:" { send "Bob\r" }; \
#		expect "Rank 2:" { send "Alice\r" }; \
#		expect "Rank 3:" { send "Charlie\r" }; \
#		interact'

#run: tideman
#	@expect -c ' \
#		spawn ./tideman ${ARGS}; \
#		expect "Number of voters: " { send "3\r" }; \
#		expect "Rank 1:" { send "Alice\r" }; \
#		expect "Rank 2:" { send "Bob\r" }; \
#		expect "Rank 3:" { send "Charlie\r" }; \
#		interact'

tideman: tideman.c
	$(CC) $(CFLAGS) tideman.c $(LIBS) -o tideman
