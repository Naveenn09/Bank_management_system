bank: main.o create.o display.o history.o search.o withdraw.o transfer.o file.o deposit.o delete.o
	cc main.o create.o display.o history.o search.o withdraw.o transfer.o file.o deposit.o delete.o -o bank

main.o: main.c bank.h
	cc -c main.c

create.o: create.c bank.h
	cc -c create.c

display.o: display.c bank.h
	cc -c display.c

history.o: history.c bank.h
	cc -c history.c

search.o: search.c bank.h
	cc -c search.c

withdraw.o: withdraw.c bank.h
	cc -c withdraw.c

transfer.o: transfer.c bank.h
	cc -c transfer.c

file.o: file.c bank.h
	cc -c file.c

deposit.o: deposit.c bank.h
	cc -c deposit.c

delete.o: delete.c bank.h
	cc -c delete.c

clean:
	rm -f bank *.o

