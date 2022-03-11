#pragma once
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "sha1.h"
#include <fstream>

void transform(uint32 (&block)[FINAL_BLOCK_INTS], uint32 (&digest)[DIGEST_INTS], std::ofstream& outputfile);

#endif