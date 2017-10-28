#ifndef config_h
#define config_h

#include <string>


// This variable isn't used outside this file, but makes specifying the other
// paths simpler.

// WINDOWS Path:
//const std:string DATA_DIR = "C:\\Users\\bjackson\\Documents\\classes\\comp494-graphics\\assignments\\asgn3-Earthquake\\data\\";

// MAC path
const std::string DATA_DIR = "/Users/lawson/documents/EarthquakeStudent/data/";

// The file to load for the earth texture.
const std::string TEXTURE_PATH = DATA_DIR + "earth-2k.jpg";

// The earthquake database file
const std::string DATA_PATH = DATA_DIR + "earthquakes.txt";

const std::string NEPTUNE_PATH = DATA_DIR + "Neptune1.jpg";

const std::string JUPITER_PATH = DATA_DIR + "Jupiter.jpg";

const std::string PLUTO_PATH = DATA_DIR + "Pluto-fiction.jpg";

const std::string SATURN_PATH = DATA_DIR + "Saturn.jpg";

const std::string MARS_PATH = DATA_DIR + "Mars2.jpg";

const std::string VENUS_PATH = DATA_DIR + "Venus2.jpg";

const std::string MERCURY_PATH = DATA_DIR + "Mercury.jpg";

const std::string URANUS_PATH = DATA_DIR + "Uranus.jpg";

const std::string SUN_PATH = DATA_DIR + "Sun.jpg";

#endif
