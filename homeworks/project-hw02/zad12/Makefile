
SRC=$(wildcard src/*c) #from source
EXESRC=$(wildcard exesrc/*c) #from exe source
OBJ=$(patsubst %.c, %.o, $(SRC)) #.o files in src
EXESRCOBJ=$(patsubst %.c, %.o, $(EXESRC)) #.o files in exesrc
INC=inc/
EXE=$(patsubst exesrc/%c, exe/%elf, $(EXESRC))


.SECONDARY:

all: $(EXE) run

exe/%.elf: exesrc/%.o $(OBJ)
	gcc $^ -o $@ -lm
	

%.o: %.c
	gcc -I $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXESRCOBJ) $(EXE)
	rm -f *.bin

run: $(EXE)	
	for file in $(EXE); do ./$$file; done
