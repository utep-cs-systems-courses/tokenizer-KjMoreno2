CFLAGS=-g

all: tokenizer

tokenizer.o: tokenizer.h
history.o: history.h tokenizer.h
uimain.o:  tokenizer.h history.h

tokenizer: tokenizer.o history.o uimain.o
	cc -o $@ $^ $(CFLAGS)
clean:
	rm -f *.o *.c~ *.h~ *~ *.c# src
run:
	./tokenizer
