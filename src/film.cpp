#include "film.hpp"

namespace phaos {

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
void
Film::write_image(std::string const& file_name)
{
  stbi_write_png(
    file_name.c_str(), width_, height_, 3, pixels_.data(), width_ * 3);
}

} // namespace phaos
