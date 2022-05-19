#ifndef _NOTE_PLAYER_HPP
#define _NOTE_PLAYER_HPP

#include "note.hpp"
#include "hwlib.hpp"
#include <sstream>
#include <string>

// ===========================================================================
//
// abstract interface for a note player
//
// ===========================================================================

class note_player {
public:   
   virtual void play( const note & n );

   std::string convert(const note& n);
};

# endif