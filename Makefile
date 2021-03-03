IDIR =include/
CC=g++
CFLAGS=-I$(IDIR)
SRC=src/

ODIR=obj

_DEPS = bookType.h Serendipity.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = addbook.o bookType.o cashier.o editbook.o invmenu.o mainmenu.o reports.o utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

serendipity: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 
