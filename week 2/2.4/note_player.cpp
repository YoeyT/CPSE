#include "note_player.hpp"

void note_player::play(const note & n)
{
    hwlib::cout << n.frequency << ", " << n.duration << '\n';
}

std::string note_player::convert(const note& n)
{
    std::ostringstream stream;

    stream << "        p.play(note{" << n.frequency << ", " << n.duration << "});\n";

    return stream.str();
}