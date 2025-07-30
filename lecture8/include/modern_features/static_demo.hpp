class Counter {
public:
  static int s_count; // Public static
  Counter() { s_count++; }

  static int get_secret() { return s_secret; }

private:
  static int s_secret; // Private static
}; // class Counter

class CounterInline {
public:
  inline static int s_count{0}; // Public static
  CounterInline() { s_count++; }

  static int get_secret() { return s_secret; }

private:
  inline static int s_secret{42}; // Private static
}; // class CounterInline

class Math {
private:
  double precision_;                        // non-static
  static inline int s_calculation_count{0}; // static

public:
  // Constructor
  Math(double precision) : precision_(precision) { s_calculation_count++; }

  // Non-static method - can access both static and non-static members
  double compute_area(double radius) {
    s_calculation_count++; // OK: access static member
    return get_pi() * radius * radius *
           precision_; // OK: access non-static member
  }

  // Static methods - can only access static members
  static double get_pi() { return 3.14159; }

  static int square(int x) {
    s_calculation_count++; // OK: access static member
    return x * x;
  }

  static int get_calculation_count() {
    return s_calculation_count; // OK: access static member
  }

  // This would cause compilation error:
  /*
  static double bad_method() {
      return precision_;          // ERROR: no access to non-static member
  }
  */
}; // class Math