//
//  memvar.h
//  GradientLayerExample
//
//  Created by Alex Shulakow on 6/21/13.
//
//

#ifndef GradientLayerExample_memvar_h
#define GradientLayerExample_memvar_h

template <typename T> struct memvar
{
private:

  T _curr;
  T _prev;
  bool _isInit;

  void lazyInit()
  {
    if (!_isInit)
      {
        _curr = _prev = 0;
        _isInit = true;
      }
  }

public:

  const memvar & operator=(memvar v)
  {
    lazyInit();

    _prev = _curr;
    _curr = v.curr();

    return *this;
  };

  const memvar & operator+(memvar v)
  {
    lazyInit();

    _prev = _curr;
    _curr += v.curr();

    return *this;
  }

  const memvar & operator-(memvar v)
  {
    lazyInit();

    _prev = _curr;
    _curr -= v.curr();

    return *this;
  }

  const memvar & operator*(memvar v)
  {
    lazyInit();

    _prev = _curr;
    _curr *= v.curr();

    return *this;
  }

  const memvar & operator/(memvar v)
  {
    lazyInit();

    if (v.curr() != 0)
      {
        _prev = _curr;
        _curr /= v.curr();
      }

    return *this;
  }

  const memvar & operator=(T v)
  {
    lazyInit();

    _prev = _curr;
    _curr = v;

    return *this;
  }

  const memvar & operator +=(T v)
        {
    lazyInit();

    _prev = _curr;
    _curr += v;

    return *this;
        };

  const memvar & operator -=(T v)
        {
    lazyInit();

    _prev = _curr;
    _curr -= v;

    return *this;
        };

  const memvar & operator *=(T v)
        {
    lazyInit();

    _prev = _curr;
    _curr *= v;

    return *this;
        };

  const memvar & operator /=(T v)
        {
    lazyInit();

    if (v != 0)
      {
        _prev = _curr;
        _curr /= v;
      }

    return *this;
        };

  T operator+(T v) { lazyInit(); return _curr + v; };
  T operator-(T v) { lazyInit(); return _curr - v; };
  T operator*(T v) { lazyInit(); return _curr * v; };
  T operator/(T v) { lazyInit(); if (v != 0) _curr / v; return _curr(); };

  /* Getters for current,previous and delta value */
public:

  T prev() { return _prev; };
  T curr() { return _curr; };
  T delta() { return _curr - _prev; };
};

typedef memvar<int> intM;
typedef memvar<float> floatM;
typedef memvar<double> doubleM;
typedef memvar<unsigned> uintM;
typedef memvar<char> charM;
typedef memvar<long> longM;

#endif
