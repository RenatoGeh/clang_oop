#ifndef _CLASS_H
#define _CLASS_H

/* A Pseudo-Object-Oriented-Programming (POOP) System for the C Language.
 * 
 * Author: Renato Lui Geh
 *
*/

#include <stdlib.h>
#include <stdarg.h>

typedef enum {
    false,
    true
} bool;

/* Definition of extends. */
#define extends(class_name) class_name* super

/* Definition of a class. */
#define class(name) typedef struct __struct_##name name; \
                    name* name##__init(int, ...); \
                    void name##__##name(name*, int, va_list); \
                    void name##__destroy(name*); \
                    void name##__destructor__##name(name*); \
                    struct __struct_##name

/* Definition of a constructor of a class. */
#define constructor(name)   name* name##__init(int n, ...) { \
                                va_list args; \
                                name* this = (name*)malloc(sizeof(name)); \
                                va_start(args, n); \
                                name##__##name(this, n, args); \
                                va_end(args); \
                                return this; \
                            } void name##__##name(name* this, int n_args, va_list args)

/* Definition of the 'new' keyword. */
#define new(name) name##__init

/* Definition of a destructor of a class. */
#define destructor(name)    void name##__destroy(name* selfie) { \
                                name##__destructor__##name(selfie); \
                                free(selfie); \
                            } void name##__destructor__##name(name* this)

/* Definition of the 'delete' keyword. */
#define delete(name, inst) name##__destroy(inst)

/* Re-definition of 'va_arg'. */
#define get_args(type) va_arg(args, type)

#endif