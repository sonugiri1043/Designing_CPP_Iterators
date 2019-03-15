/* 
   Compile using 'g++ Custom_Iterator.cpp -o Custom_Iterator --std=c++11'
*/

#include "Custom_Iterator.h"

using custom_iterator::vector;

int main() {
  vector< int > myVector;
  myVector.push_back( 10 );
  myVector.push_back( 20 );
  myVector.push_back( 30 );

  for( int i = 0; i < myVector.size(); i++ ) {
    cout << myVector[ i ] << endl;
  }

  vector<int>::iterator iter;
  for( iter = myVector.begin(); iter != myVector.end(); ++iter ) {
    *iter += 20;
    cout << *iter << endl;
  }
  
  for( iter = myVector.rbegin(); iter != myVector.rend(); --iter ) {
    *iter -= 20;
    cout << *iter << endl;
  } 
  return 0;
}
