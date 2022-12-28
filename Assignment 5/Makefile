$(CC) = gcc
$(CFLAGS) = -Wall -Wextra -Wpendantic -std=c99 

output: worldCupDB.o worldcup_team.o worldcup_player.o
	$(CC) worldCupDB.o worldcup_team.o worldcup_player.o -o output

worldCupDB.o: worldCupDB.c worldCupDB.h
	$(CC) -c worldCupDB.c

worldcup_team.o: worldcup_team.c worldcup_team.h
	$(CC) -c worldcup_team.c

worldcup_player.o: worldcup_player.c worldcup_player.h
	$(CC) -c worldcup_player.c

clean:
	rm *.o output
