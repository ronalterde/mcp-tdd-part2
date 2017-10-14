MCU = atmega32
CXX = avr-g++
CXXFLAGS = -mmcu=$(MCU) -std=c++11 -O0 -fno-rtti -Wall

.PHONY: all
all: mcp-dynamic mcp-dynamic-stats mcp-static mcp-static-stats

.PHONY: mcp-dynamic-stats
mcp-dynamic-stats: mcp-dynamic
	avr-readelf -S mcp-dynamic

.PHONY: mcp-static-stats
mcp-static-stats: mcp-static
	avr-readelf -S mcp-static

mcp-dynamic: mcp-dynamic.cpp can.o boilerplate.h
	$(CXX) $(CXXFLAGS) -Wa,-alhnd $< -o $@ | avr-c++filt > $@.lst

mcp-static: mcp-static.cpp can.o boilerplate.h
	$(CXX) $(CXXFLAGS) -Wa,-alhnd $< -o $@ | avr-c++filt > $@.lst

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f *.lst
	rm -f mcp-dynamic
	rm -f mcp-static
