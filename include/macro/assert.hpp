//
// Created by asuna on 3/6/2020.
//

#ifndef ENGINE_ASSERT_HPP
#define ENGINE_ASSERT_HPP
#define BREAKPOINT \
    asm("int $3")

#define ASSERT(x) if (!(x)) { fprintf( stderr, ""); BREAKPOINT; }


#endif //ENGINE_ASSERT_HPP
