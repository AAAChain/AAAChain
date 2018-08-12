#pragma once


namespace reflect {
  using std::size_t;
  typedef decltype(nullptr) nullptr_t;


  struct true_type  { enum _value { value = 1 }; };
  struct false_type { enum _value { value = 0 }; };
  
  namespace detail {
    template<typename T> fc::true_type is_class_helper(void(T::*)());
    template<typename T> fc::false_type is_class_helper(...);
  }

}
