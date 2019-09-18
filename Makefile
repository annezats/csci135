#make keeps track of timestamp so it knows whether something is upto date
#or if it needs to compile it again

# target: dependencies
#  rule (command)

main: main.o addfuncs.o
  g++ -o main main.o addfuncs.o

main.o : main.cpp addfuncs.h
	g++ -c main.cpp #this is unnecessary cause make does it automatically

addfuncs.o: addfuncs.cpp addfuncs.h #have to write all dependencies
	g++ -c addfuncs.cpp

clean:
	m main.o addfuncs.o   #cleans things

help:
  echo @"this is some help"         #echo is like print for the terminal
                                # @ means it doesn't print
chained: one
  @echo "i;m running chained"  #chained is dependent on one

one:                  #so first one happens then chained happens
  @echo "i'm running one"
