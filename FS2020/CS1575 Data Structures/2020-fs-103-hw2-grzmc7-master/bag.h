/* TODO1: Create an abstract templated class 'Bag' which will serve as an
    interface to the two other derived bag implementations.

 * You must include the following *pure virtual* functions:
    - insert()
    - remove()
    - size()

    - remember, you do not need to have an implementation body for a PVF; thus,
        you do not need a bag.hpp file

 * The name of the templated abstract class (templated on T) should be Bag, look
    at the header files of the other two bag implementations for guidance

 * TODO2: Include a public member variable in your abstract class
    - std::string parent_variable = "this is from the abstract class";
 */

#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <string>
#include "my_exception.h"
using std::string;

void get_identity(string &my_id);

// implement your abstract class here:
template <class T>
class Bag
{
   public:

      std::string parent_variable = "this is from the abstract class";

      //Modification member functions
      virtual bool insert(const T &myItem) = 0;

      virtual bool remove(const T &myItem) = 0;

      //constant member function.
      virtual int size() const = 0;

};

#endif
