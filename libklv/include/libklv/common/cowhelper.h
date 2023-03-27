// Copyright (c) 2023. Keshav Jat
#ifndef LIBKLV_COWHELPER_H
#define LIBKLV_COWHELPER_H

#include "globals.h"

#include <atomic>

namespace kj::ber {

class LIBKLV_EXPORT CowData {
public:
  std::atomic_int refCount;

  inline CowData() noexcept : refCount{0} {}
  inline CowData(const CowData & /*other*/) noexcept : refCount{0} {}

  ~CowData() = default;

  CowData &operator=(const CowData & /*other*/) = delete;
};

template <typename T> class LIBKLV_EXPORT CowDataPointer {
public:
  inline CowDataPointer() : _data{nullptr} {}
  inline ~CowDataPointer() {
    // Release resources if ref become 0
    if (_data && !(--_data->refCount))
      delete _data;
  }

  inline T &operator*() {
    detach();
    return *_data;
  }
  inline const T &operator*() const { return _data; }

  inline T *operator->() {
    detach();
    return _data;
  }
  inline const T *operator->() const { return _data; }

  inline operator T *() {
    detach();
    return _data;
  }
  inline operator const T *() const { return _data; }

  inline T *data() {
    detach();
    return _data;
  }

  bool operator==(const CowDataPointer<T> &other) const { return _data == other._data; }
  bool operator!=(const CowDataPointer<T> &other) const { return !(operator==(other)); }

  inline void detach() {
    if (_data && _data->refCount.load(std::memory_order_relaxed) != 1)
      _detachData();
  }

  inline const T *data() const { return _data; }
  inline const T *constData() const { return _data; }

private:
  T *_clone();
  void _detachData();

  T *_data;
};
template <typename T> inline T *CowDataPointer<T>::_clone() { return new T(*_data); }

template <typename T> inline void CowDataPointer<T>::_detachData() {
  T *temp = _clone();
  // Make current ref count 1
  temp->refCount++;

  // If existing data's ref count become zero, then delete it.
  if (!(--_data->refCount)) {
    delete _data;
  }

  _data = temp;
}

} // namespace kj::ber

#endif // LIBKLV_COWHELPER_H
