/*
  dense_matrix
*/

namespace marlib {

  class vector {
  public:

    using value_type = double;

    vector(int size, double* v)
    : m_size(size), m_value(v), m_inc(1) {}

    ~vector() {}

  private:
    int m_size;
    double* m_value;
    int m_inc;

  public:
    double& operator[](int i) { return m_value[i]; };
    const double& operator[](int i) const { return m_value[i]; };

    int size() const { return m_size; }
    int inc() const { return m_inc; }

    ////// print
    std::ostream& print(std::ostream& os) const {
      for (int i=0; i<m_size; i++) {
        os << m_value[i] << " ";
      }
      os << std::endl;
      return os;
    }

    friend std::ostream& operator<< (std::ostream& os, const vector& m);
  };

  inline
  std::ostream& operator<<(std::ostream& os, const vector& m) {
    return m.print(os);
  }

  template <>
  struct get_category<vector> {
    using type = double_vector_tag;
  };

}