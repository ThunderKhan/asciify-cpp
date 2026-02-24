#include <iostream>
#include <fstream>
#include <asciify/image_loader.hpp>
#include <asciify/ascii_mapper.hpp>

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image-path> [output-file]\n";
        return 1;
    }

    try {
        auto img = asciify::load_image(argv[1]);
        std::cout << "Loaded image: " << img.width
                  << " x " << img.height
                  << ", channels=" << img.channels << "\n";

        std::string ascii = asciify::image_to_ascii(img);

        if (argc >= 3) {
            std::ofstream ofs(argv[2]);
            if (!ofs) {
                std::cerr << "Error: can't open output file " << argv[2] << "\n";
                return 1;
            }
            ofs << ascii;
            std::cout << "ASCII art saved to " << argv[2] << "\n";
        } else {
            std::cout << ascii;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
