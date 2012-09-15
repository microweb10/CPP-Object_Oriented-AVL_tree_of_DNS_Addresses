OBJ = tad.o tavldir.o tlistadir.o tvectordir.o tdir.o thashdir.o
OPC = -g
COMP = g++

all: tad

tad: $(OBJ)
	$(COMP) $(OPC) $(OBJ) -o tad
tad.o: tad.cc tavldir.h tlistadir.h tdir.h tvectordir.h thashdir.h
	$(COMP) $(OPC) -c tad.cc
tlistadir.o: tlistadir.h
	$(COMP) $(OPC) -c tlistadir.cc
thashdir.o: thashdir.h
	$(COMP) $(OPC) -c thashdir.cc
tavldir.o: tavldir.h
	$(COMP) $(OPC) -c tavldir.cc
tvectordir.o: tvectordir.h 
	$(COMP) $(OPC) -c tvectordir.cc
tdir.o: tdir.h 
	$(COMP) $(OPC) -c tdir.cc


clean:
	-rm -rf tad *.o
