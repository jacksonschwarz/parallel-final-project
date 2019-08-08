
CC=mpicc
CPP=g++
LDC=mpicc
LDP=mpicc
LD_FLAGS = -lstdc++ -lopencv_core -lopencv_highgui -lopencv_imgproc -fopenmp
FLAGS= -I/usr/include/opencv -fopenmp
PROGC = dijkstraParallel.x
OBJSC = dijkstraParallel.o

RM = /bin/rm

#all rule
all: $(PROGC) $(PROGF)

$(PROGC): $(OBJSC)
	$(LDP) $^ $(LD_FLAGS) -o $@
%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@
%.o: %.cpp
	$(CPP) $(FLAGS) -c $^ -o $@


#clean rule
clean:
	$(RM) -rf *.o $(PROGC) *.mod *.o* 
