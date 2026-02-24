#include "asciify/image_loader.hpp"

#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include "../vendor/stb/stb_image.h"

namespace asciify {

Image load_image( const std::string& path ) {
    int w, h, c;

    unsigned char* raw =
        stbi_load(path.c_str(), &w, &h, &c, 0);

    if (!raw)
        throw std::runtime_error( stbi_failure_reason() );

    Image img;
    img.width   = w;
    img.height  = h;
    img.channels = c;
    img.data.assign( raw, raw + ( w * h * c ) );

    stbi_image_free(raw);

    return img;
}

}
