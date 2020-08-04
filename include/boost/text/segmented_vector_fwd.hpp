// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_TEXT_SEGMENTED_VECTOR_FWD_HPP
#define BOOST_TEXT_SEGMENTED_VECTOR_FWD_HPP

#include <vector>


namespace boost { namespace text {
    template<typename T, typename Segment = std::vector<T>>
    struct segmented_vector;

}}

#endif
