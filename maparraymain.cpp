#include <iostream>
#include "maparray.h"
#include <string>
#include <functional>
#include <algorithm>
#include "maparray.h"
#include <map>

struct string_size_less
{
  bool operator()( const std::string& a, const std::string& b ) const
  {
    return a.size() < b.size();
  }

};

const int max = 1000;

int main()
{
  int your_mark = 1;
  // 2-es
  std::map<int, int> b;
  int v[ max ];
  for( int i = 1; i <= max; ++i )
  {
    b[ i * 2 ] = i;
    v[ i - 1 ] = i;
  }
  const map_array_util<int, int> ut( b );

  std::map<std::string, int> s;
  s[ "C++" ] = 1;
  s[ "Python" ] = 2;
  map_array_util<std::string, int> uls( s );


  std::map<int, std::string> a;
  a[ 5 ]; a[ 1 ]; a[ 2 ];
  std::string msg[] = { "I", "<3", "C++" };
  map_array_util<int, std::string> um( a );
  um.copy( msg, sizeof( msg ) / sizeof( msg[ 0 ] ) );

  if ( ut.equals( v, max ) && !uls.equals( v, max ) && 3 == a.size() &&
       um.equals( msg, sizeof( msg ) / sizeof( msg[ 0 ] ) ) &&
       "C++" == a[ 5 ] && 0 == a.count( 0 )  && 0 == a.count( 3 ) )
  {
    your_mark = a[ 2 ].length();
  }
  
  // 3-as
  int na[] = {3, 7};
  uls.swap( na, sizeof( na ) / sizeof( na[ 0 ] ) );

  std::swap( v[ 0 ], v[ 1 ] );
  std::swap( v[ 0 ], v[ max / 2 ] );

  if ( !ut.permutation( na, sizeof( na ) / sizeof( na[ 0 ] ) ) &&
       !uls.equals( na, sizeof( na ) / sizeof( na[ 0 ] ) ) &&
       your_mark == s.size() && 7 == s[ "Python" ] &&
       !ut.equals( v, max ) && ut.permutation( v, max ) )
  {
    your_mark = s[ "C++" ];
  }
  
  /* 4-es
  std::map<std::string, std::string, string_size_less> ml;
  ml[ "C++" ] = ":-)";
  ml[ "Cobol" ] = ":-S";
  map_array_util<std::string, std::string, string_size_less> mlu( ml );

  std::string e[] = { ":-D", ":-(", ":-/" };
  mlu = e;

  std::map<int, double, std::greater<int> > mg;
  mg[ 2 ] = 3.3;
  mg[ 5 ] = 8.3;
  mg[ 1 ] = 3.9;
  mg[ 7 ] = 8.8;
  map_array_util<int, double, std::greater<int> > mgu( mg );
  double d[] = { 7.3, 9.2 };
  mgu = d;

  if ( 7.8 >  mg.begin()->second && 8.6 < mg[ 5 ] &&
        ":-(" == ml[ "Forth" ] && ":-D" == ml[ "Ada" ] )
  {
    your_mark = mg.size();
  }
  */
  /* 5-os
  std::map<std::string, int, string_size_less> x;
  std::map<std::string, int, string_size_less> y;
  x[ "C++" ] = 4;
  x[ "Python" ] = 5;
  y[ "C" ] = 4;
  y[ "SQL" ] = 5;
  map_array_util<std::string, int, string_size_less> yu( y );
  std::map<std::string, int> cx( x.begin(), x.end() );

  std::map<int, int> bc = b;
  std::swap( bc[ 4 ], bc[ 2 ] );

  map_array_util<int, int> bcu( bc );

  if ( x == yu && !( bcu == b ) && ( b *= bcu ) &&
       ( yu *= x )  && ( ut *= bcu ) && !( uls *= cx ) )
  {
    your_mark = y[ "C++" ];
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}