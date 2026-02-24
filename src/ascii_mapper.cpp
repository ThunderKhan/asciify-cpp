#include "asciify/ascii_mapper.hpp"

#include <sstream>

namespace asciify {
  
  std::string image_to_ascii(const Image &img) {
    const char* ramp = " .:-=+*#%@";
    const int rampSize = 10;

    std::stringstream ss;

    int w = img.width;
    int h = img.height;
    int c = img.channels;

    for ( int y = 0; y < h; y += 2 ) {
      for ( int x = 0; x < w; ++x ) {
        int idx = (y * w + x) * c;

        unsigned char r = img.data[ idx + 0 ];
        unsigned char g = img.data[ idx + 1 ];
        unsigned char b = img.data[ idx + 2 ];

        float gray = 0.2126f * r + 0.7152f * g + 0.0722f * b;

        int rampIdx = static_cast<int> (( gray / 255.0f ) * ( rampSize - 1 ));
        ss << ramp[rampIdx];
      }
      ss << "\n";
    }

    return ss.str();
  }
}
