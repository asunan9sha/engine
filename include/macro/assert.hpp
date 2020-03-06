//
// Created by asuna on 3/6/2020.
//

#ifndef ENGINE_ASSERT_HPP
#define ENGINE_ASSERT_HPP

#define BREAKPOINT    __debugbreak()

#define ASSERT(x) if (!(x)) { \
fprintf( stderr, "assertion failed ( %s ), %s, %i \n", #x,__FILE__,__LINE__); \
BREAKPOINT; }


#endif //ENGINE_ASSERT_HPP
