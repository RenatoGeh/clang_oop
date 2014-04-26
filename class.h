#ifndef _CLASS_H
#define _CLASS_H

/* A Pseudo-Object-Oriented-Programming (POOP) System for the C Language.
 * 
 * Author: Renato Lui Geh
 *
*/

#include <stdlib.h>

typedef enum {
    false,
    true
} bool;

/* Definition of extends. */
#define extends(class_name) class_name* super

/* Definition of a class. */
#define class(name) typedef struct __struct_##name name; \
                    name* name##__init(); \
                    void name##__##name(name*); \
                    void name##__destroy(name*); \
                    void name##__destructor__##name(name*); \
                    struct __struct_##name

/* Definition of a constructor of a class. */
#define constructor(name)   name* name##__init() { \
                                name* this = (name*)malloc(sizeof(name)); \
                                name##__##name(this); \
                                return this; \
                            } void name##__##name(name* this)

/* Definition of the 'new' keyword. */
#define new(name) name##__init()

/* Definition of a destructor of a class. */
#define destructor(name)    void name##__destroy(name* selfie) { \
                                name##__destructor__##name(selfie); \
                                free(selfie); \
                            } void name##__destructor__##name(name* this)

/* Definition of the 'delete' keyword. */
#define delete(name, inst) name##__destroy(inst)

#define decl_func(classname, name) Class##name_##name
    
/*  A complete example on this POOP system would be:
 *
 *  class(YTwist) {
 *      const char* error = "Unexpected ending.";
 *      List elements;
 *      int current;
 *      // A function do_the_twist:R->R that twists the Y-axis.
 *      double (*do_the_twist)(YTwist*, double); 
 *  };
 *
 *  Here we can see we can give constant values to members just as
 *  we would in a struct. We can also have other classes as members.
 *  Now on to the actual body implementation of the class YTwist.
 *  
 *  double do_the_twist_impl(YTwist* this, double x) {
 *      double y = doStuff(x);
 *      this->elements->add(y);
 *      ++current;
 *  }
 *
 *  constructor(YTwist) {
 *      this->elements = new(List);
 *      this->current = 0;
 *      this->do_the_twist = do_the_twist_impl;
 *  }
 *
 *  destructor(YTwist) {
 *      delete(List, this->elements);
 *  }
 *
 *  In this system both constructor and destructor MUST be explicitly
 *  implemented.
 *  Also note that the constructor must be placed after all member
 *  function implementations. Or at least their prototypes.
 *  
 *  int main(int argc, char* args[]) {
 *      YTwist* twister = new(YTwist);
 *      double value;
 *      value = twist_and_shout(twister);
 *      if(twister->current == 0) puts(twister->error);
 *      else twister->do_the_twist(twister, value);
 *      delete(YTwist, twister)
 *      return 0;
 *  }
*/

#endif