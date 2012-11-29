F = gfortran
FFLAGS = -ggdb
PACKNAME = fortran_example

OBJS = gradient.o gradientmain.o
TESTS = test1.tst test2.tst test3.tst test4.tst

all: clean $(OBJS)

run: $(OBJS) $(TESTS)
	for file in $$(ls *.tst); do ./$$file; done

cuter: $(PACKNAME)main.o
	cp -f $(PACKNAME).sh.pro $(CUTER)/build/prototypes/$(PACKNAME).sh.pro
	cp -f gradient.o $(MYCUTER)/double/bin
	sed -f $(MYCUTER)/double/config/script.sed $(PACKNAME).sh.pro > $(MYCUTER)/bin/$(PACKNAME)
	chmod a+x $(MYCUTER)/bin/$(PACKNAME)
	cp -f $(PACKNAME)main.f $(MYCUTER)/double/bin/$(PACKNAME)ma.f
	cp -f $(PACKNAME)main.o $(MYCUTER)/double/bin/$(PACKNAME)ma.o

clean:
	rm -f $(OBJS) $(TESTS)

purge: clean

%.o: %.f
	$(F) -c -o $@ $< $(FFLAGS)

%.tst: %.f
	$(F) -o $@ $< $(FFLAGS) $(OBJS)
