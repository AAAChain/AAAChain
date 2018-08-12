#pragma once


namespace reflect {
  using std::size_t;
  typedef decltype(nullptr) nullptr_t;


  struct true_type  { enum _value { value = 1 }; };
  struct false_type { enum _value { value = 0 }; };
}
