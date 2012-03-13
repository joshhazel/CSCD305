//Source taken from https://bitbucket.org/kniht/scraps/src/01ecc1346bc5/cpp/kniht/clinput.hpp


#include<istream>
#include<limits>

namespace kniht {

void pause(char const* prompt="Press ENTER to continue.");
bool yesno(char const* prompt, bool default_yes=true);


template<class C, class T>
std::basic_istream<C,T>& ignorefield(std::basic_istream<C,T>& s, typename std::basic_istream<C,T>::char_type delim) {
  s.ignore(std::numeric_limits<std::streamsize>::max(), delim);
  return s;
}

template<class C, class T>
std::basic_istream<C,T>& ignoreline(std::basic_istream<C,T>& s) {
  ignorefield(s, s.widen('\n'));
  return s;
}

template<class C, class T>
std::basic_istream<C,T>& clearfield(std::basic_istream<C,T>& s, typename std::basic_istream<C,T>::char_type delim) {
  s.clear();
  ignorefield(s, delim);
  return s;
}

template<class C, class T>
std::basic_istream<C,T>& clearline(std::basic_istream<C,T>& s) {
  clearfield(s, s.widen('\n'));
  return s;
}

template<class C, class T>
std::basic_istream<C,T>& blankfield(std::basic_istream<C,T>& s, typename std::basic_istream<C,T>::char_type delim) {
  if (s) {
    typename std::basic_istream<C,T>::char_type input;
    if (!s.get(input) && s.eof()) {
      s.clear(s.eofbit);
    }
    else if (input != delim) {
      s.putback(input);
      s.setstate(s.failbit);
    }
  }
  return s;
}

template<class C, class T>
std::basic_istream<C,T>& blankline(std::basic_istream<C,T>& s) {
  blankfield(s, s.widen('\n'));
  return s;
}

template<class C>
struct Blankfield {
  C delim;

  explicit
  Blankfield(C delim)
  : delim(delim)
  {}

  template<class T>
  friend
  std::basic_istream<C,T>& operator>>(std::basic_istream<C,T>& s, Blankfield const& v) {
    blankfield(s, v.delim);
    return s;
  }

  template<class C2, class T>
  friend
  std::basic_istream<C2,T>& operator>>(std::basic_istream<C2,T>& s, Blankfield const& v) {
    blankfield(s, s.widen(v.delim));
    return s;
  }
};

template<class C>
Blankfield<C> blankfield(C delim) {
  return Blankfield<C>(delim);
}


// different from blankline in how it handles EOF
// needs more thought
template<class C, class T>
std::basic_istream<C,T>& endl(std::basic_istream<C,T>& s) {
  if (s) {
    typename std::basic_istream<C,T>::char_type input;
    if (!s.get(input)) {
      // error reading; stream handles it
    }
    else if (input != s.widen('\n')) {
      s.putback(input);
      s.setstate(s.failbit);
    }
  }
  return s;
}

} // kniht::
