#pragma once
#include "BitGroup.h"

BitUnit GetIndex(BitGroup& vbu, size_t index);
bool EqualityCheck(BitGroup rhs, BitGroup lhs);
BitGroup Negate(BitGroup lhs);
BitGroup Sum(BitGroup rhs, BitGroup lhs);
BitGroup GetAnd(BitGroup lhs, BitGroup rhs);
BitGroup GetOr(BitGroup lhs, BitGroup rhs);
BitGroup GetXOr(BitGroup lhs, BitGroup rhs);

BitGroup ShiftLeft(BitGroup lhs, size_t movement);
BitGroup ShiftRight(BitGroup lhs, size_t movement);
BitGroup RotateLeft(BitGroup lhs, size_t movement);
BitGroup RotateRight(BitGroup lhs, size_t movement);

BitGroup AppendTwoBitGroups(BitGroup base, BitGroup x);
BitGroup PrependTwoBitGroups(BitGroup base, BitGroup x);

BitGroup LeastSignificantBits(BitGroup x, size_t number);

BitGroup ExtractBitsFromWord(BitGroup x, size_t start, size_t length);