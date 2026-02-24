#pragma once

#include <vector>
#include <string>

namespace asciify {
  struct Image {
    int width;
    int height;
    int channels;
    std::vector<unsigned char> data;
  };

  Image load_image(const std::string& path);
}
