CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++14 -pedantic -Wall

SRCS=$(shell find . -name "*.cpp")
OBJS=$(subst .cpp,.o,$(SRCS))

all: output

output: $(OBJS)
	$(CXX) -o output $(OBJS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend