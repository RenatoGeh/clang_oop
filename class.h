#ifndef _CLASS_H
#define _CLASS_H

/* Definition of a class. */
#define class(name) typedef struct __struct_##name ##name; \
					##name* ##name::init(); \
					void ##name::##name(##name*); \
					void ##name::destroy(##name*); \
					void ##name::~##name(##name*); \
					struct __struct_##name

class(Object) {
	int id;
};

/* Definition of a constructor of a class. */

#define constructor(name) 	##name* ##name::init() { \
								##name* selfie = (##name*)malloc(sizeof(##name)); \
								##name::##name(selfie); \
								return selfie; \
							} void ##name::##name(##name* this)

constructor(Object) {
	this->id = 0;
} 

/* Definition of the 'new' keyword. */
#define new(name) ##name::init()


/* Definition of a destructor of a class. */
#define destructor(name) 	##name* ##name::destroy(##name* selfie) { \
								##name::~##name(selfie); \
								free(selfie); \
							} void ##name::~##name(##name* this)

destructor(Object) {

}

/* Definition of the 'delete' keyword. */
#define delete(name, inst) ##name::destroy(inst);

/** Thus a complete example on this pseudo-OOP system would be:
 *
 *  class(YTwist) {
 *		char* error = "Unexpected ending.";
 *		List elements;
 *		int current;
 *		// A function do_the_twist:R->R that twists the Y-axis.
 *      double (*do_the_twist)(YTwist*, double); 
 *  }
 *
 *  Here we can see we can give constant values to members just as
 *  we would in a struct. We can also have other classes as members.
 *  Now on to the actual body implementation of the class YTwist.
 *  
 *  double do_the_twist_impl(YTwist* this, double x) {
 *		double y = doStuff(x);
 *		this->elements->add(y);
 *		++current;
 *	}
 *
 *  constructor(YTwist) {
 *		this->elements = new(List);
 *		this->current = 0;
 *		this->do_the_twist = do_the_twist_impl;
 *	}
 *
 *  destructor(YTwist) {
 *		delete(List, this->elements);
 *	}
 *
 *  In this system both constructor and destructor MUST be explicitly
 *  implemented.
 *  Also note that the constructor must be placed after all member
 *  function implementations. Or at least their prototypes.
 *  
 *  int main(int argc, char* args[]) {
 *		YTwist* twister = new(YTwist);
 *		double value;
 *		value = twist_and_shout(twister);
 *		if(twister->current == 0) puts(twister->error);
 *		else twister->do_the_twist(twister, value);
 *		delete(YTwist, twister)
 *		return 0;
 *	}
*/

#endif