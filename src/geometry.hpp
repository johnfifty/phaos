#include <cmath>

namespace phaos {

using real_t = float;

struct vec3
{
  real_t x, y, z;
};

constexpr auto
operator+(vec3 const& v1, vec3 const& v2) noexcept -> vec3
{
  return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

constexpr auto
operator-(vec3 const& v1, vec3 const& v2) noexcept -> vec3
{
  return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

constexpr auto
operator*(real_t c, vec3 const& v) noexcept -> vec3
{
  return { c * v.x, c * v.y, c * v.z };
}

[[nodiscard]] constexpr auto
dot(vec3 const& v1, vec3 const& v2) noexcept -> real_t
{
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

[[nodiscard]] constexpr auto
length2(vec3 const& v) noexcept -> real_t
{
  return dot(v, v);
}

[[nodiscard]] constexpr auto
length(vec3 const& v) noexcept -> real_t
{
  return std::sqrt(dot(v, v));
}

[[nodiscard]] constexpr auto
norm(vec3 const& v) noexcept -> vec3
{
  return (real_t{ 1.0F } / length(v)) * v;
}

[[nodiscard]] constexpr auto
cross(vec3 const& v1, vec3 const& v2) noexcept -> vec3
{
  return { v1.y * v2.z - v1.z * v2.y,
           v1.z * v2.x - v1.x * v2.z,
           v1.x * v2.y - v1.y * v2.x };
}

struct Color
{
  real_t r, g, b;
};

} // namespace phaos
