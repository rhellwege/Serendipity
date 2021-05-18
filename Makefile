IDIR =include/
CC=g++
CFLAGS=-I$(IDIR) -lX11 -g
SRC=src/

ODIR=obj

_DEPS = bookType.h Serendipity.h templates.hpp linkedList.h orderedLinkedList.h unorderedLinkedList.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = addbook.o bookType.o editbook.o invmenu.o mainmenu.o utils.o reports.o cashier.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

serendipity: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 
