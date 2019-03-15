#include <iostream>

using std::cout;
using std::endl;

namespace custom_iterator {

  template< typename T > class vector {
  public:
    vector() {
      size_ = 0;
      capacity = CAPACITY;
      data = new T[ capacity ];
    }

    ~vector() {
      delete [] data;
      data = NULL;
      size_ = 0;
    }

    /* iterator class */
    class iterator {
    public:
      iterator() {}

      iterator( T *ptr ) {
	current = ptr;
      }

      /* overload != operator */
      bool operator!=( const iterator &rhs ) {
	return this->current != rhs.current;
      }

      /* overload prefix ++ operator */
      iterator& operator++() {
	++current;
	return *this;
      }

      /* overload prefix -- operator */
      iterator& operator--() {
	--current;
	return *this;
      }

      /* overload * (de-reference) operator */
      T& operator*() {
	return *current;
      }

    private:
      T *current;
    }; /* iterator class ends here */

    iterator begin() const {
      return iterator( data );
    }
    
    iterator end() const {
      return iterator( data + size_ );
    }

    /* reverse begin */
    iterator rbegin() const {
      return iterator( data + size_ - 1 );
    }
    
    /* reverse end */
    iterator rend() const {
      return iterator( data - 1 );
    }

    int size() {
      return size_;
    }
    
    void push_back( const T &value ) {
      if( size_ == capacity )
	expand();
      data[ size_ ] = value;
      size_++;
    }

    const T& operator[]( int pos ) const {
      return data[ pos ];
    }

    T& operator[]( int pos ) {
      return data[ pos ];
    }
  private:
    void expand();
    const int CAPACITY = 16;
    unsigned int size_;
    unsigned int capacity;
    T *data;
  };

  template<typename T>
    void vector<T>::expand() {
    capacity += CAPACITY;
    T *newData = new T[ capacity ];
    for( int i = 0; i < size_; i++ ) {
      newData[ i ] = data[ i ];
    }
    delete [] data;
    data = newData;
  }

} // namespace custom_iterator ends
