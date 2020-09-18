/*

Copyright (c) 2015, 2017, 2019-2020, Arvid Norberg
All rights reserved.

You may use, distribute and modify this code under the terms of the BSD license,
see LICENSE file.
*/

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "test.hpp"
#include "libtorrent/time.hpp"
#include "libtorrent/download_priority.hpp"

#include "libtorrent/sha1_hash.hpp"
#include "libtorrent/aux_/vector.hpp"
#include "libtorrent/aux_/path.hpp"
#include <vector>
#include <fstream>

namespace libtorrent
{
	EXPORT char const* time_now_string();
	EXPORT char const* time_to_string(lt::time_point const tp);
}

inline lt::download_priority_t operator "" _pri(unsigned long long const p)
{
	return lt::download_priority_t(static_cast<std::uint8_t>(p));
}

EXPORT lt::aux::vector<lt::sha256_hash> build_tree(int const size);

#ifdef _WIN32
int EXPORT truncate(char const* file, std::int64_t size);
#endif

struct EXPORT ofstream : std::ofstream
{
	ofstream(char const* filename);
};

#endif

