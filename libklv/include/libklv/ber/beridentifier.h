// Copyright (c) 2023. Keshav Jat

#ifndef LIBKLV_BERIDENTIFIER_H
#define LIBKLV_BERIDENTIFIER_H

#include <cstdint>

namespace kj::ber {

class BerIdentifier {
public:
  BerIdentifier() = delete;

private:
  ::uint8_t *_data;
  ::int16_t _size;
};

} // namespace kj::ber

#endif // LIBKLV_BERIDENTIFIER_H
