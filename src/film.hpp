#include "geometry.hpp"

#include <algorithm>
#include <cmath>

namespace phaos {

constexpr real_t gamma = 2.2F;

class Film
{
  struct rgb
  {
    std::uint8_t r, g, b;

    explicit rgb(Color const& color)
    {
      auto clamp = [](real_t val) {
        return std::clamp<real_t>(val, 0.0F, 1.0F);
      };
      auto gamma_correct = [](real_t val) {
        return std::pow(val, 1.0F / gamma);
      };

      r = std::uint8_t(std::floor(clamp(gamma_correct(color.r)) * 255.0F));
      g = std::uint8_t(std::floor(clamp(gamma_correct(color.g)) * 255.0F));
      b = std::uint8_t(std::floor(clamp(gamma_correct(color.b)) * 255.0F));
    }
  };

  int width_;
  int height_;
  std::vector<rgb> pixels_;

public:
  void set_pixel(int x, int y, Color const& c)
  {
    pixels_[x + width_ * y] = rgb(c);
  }

  void write_image(std::string const& file_name);
};

} // namespace phaos
