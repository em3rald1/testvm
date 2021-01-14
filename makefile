c=g++
cflags=-std=c++11 -w
objflag=-c
debugflag=-g
releaseflag=-O3

objram=bin/ram.o
objcpu=bin/cpu.o
objbus=bin/bus.o
objssd=bin/ssd.o
objssdmap=bin/ssdmap.o
objmain=bin/main.o

includeflag=-I ./

cbus=src/bus.cpp
ccpu=src/cpu.cpp
cram=src/ram.cpp
cssd=src/ssd.cpp
cssdmap=src/ssdmap.cpp
cmain=main.cpp

all: $(objram) $(objcpu) $(objbus) $(objssd) $(objssdmap) $(objmain)
	$(c) $(cflags) $(objram) $(objcpu) $(objbus) $(objssd) $(objssdmap) $(objmain) -o main

$(objram): $(cram)
	$(c) $(cflags) $(objflag) $(debugflag) $(includeflag) $(cram) -o $(objram)

$(objcpu): $(ccpu)
	$(c) $(cflags) $(objflag) $(debugflag) $(includeflag) $(ccpu) -o $(objcpu)

$(objbus): $(cbus)
	$(c) $(cflags) $(objflag) $(debugflag) $(includeflag) $(cbus) -o $(objbus)

$(objssd): $(cssd)
	$(c) $(cflags) $(objflag) $(debugflag) $(includeflag) $(cssd) -o $(objssd)

$(objssdmap): $(cssdmap)
	$(c) $(cflags) $(objflag) $(debugflag) $(includeflag) $(cssdmap) -o $(objssdmap)

$(objmain): $(cmain)
	$(c) $(cflags) $(objflag) $(debugflag) $(includeflag) $(cmain) -o $(objmain)
