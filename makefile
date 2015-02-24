TOP=..

include ../make.common

LIBOBJS=\
    $(VPATH)/atime.o \
    $(VPATH)/SimulationMgr.o \
    $(VPATH)/order.o \
    $(VPATH)/movable.o \
    $(VPATH)/carrier.o \
    $(VPATH)/cruiser.o \
    $(VPATH)/fighter.o \
    $(VPATH)/location.o 

LIBDEP = $(LIBOBJS:.o=.d)
OBJECTS = $(LIBOBJS)

NAVYLIB=libNavy.a

all: $(NAVYLIB)

# $(CXX) -MD creates a .d file and a .o file in the VPATH directory
$(LIBDEP):      $(VPATH)/%.d:   %.cpp
	-mkdir -p $(VPATH)
	$(CXX) -MD $(CXXFLAGS)  -o $(@:.d=.o) $<


$(OBJECTS): $(VPATH)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(NAVYLIB): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -rf $(NAVYLIB) $(VPATH)

include $(OBJECTS:.o=.d)
