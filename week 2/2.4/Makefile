#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp
SOURCES += note_player.cpp
HEADERS += fur_elise.hpp
SOURCES += converted_melody.cpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += rtttl_player.hpp
SOURCES += rtttl_player.cpp

# other places to look for files for this project
SEARCH  :=

converted_melody.cpp : main.exe
	./main.exe > converted_melody.cpp

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
