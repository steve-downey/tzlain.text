// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DETAIL_BIDIRECTIONAL_HPP
#define BOOST_TEXT_DETAIL_BIDIRECTIONAL_HPP

#include <boost/text/bidirectional_fwd.hpp>

#include <algorithm>
#include <array>

#include <stdint.h>


namespace boost { namespace text { namespace detail {

enum class bidi_bracket_type {
    open,
    close
};

struct bidi_bracket_data
{
    explicit operator bool() const { return cp_ != 0; }

    uint32_t cp_;
    uint32_t paired_bracket_;
    bidi_bracket_type type_;
};

inline bidi_bracket_data bidi_bracket(uint32_t cp)
{
    static std::array<bidi_bracket_data, 128> const brackets = {{
        {0x0028, 0x0029, bidi_bracket_type::open},
        {0x0029, 0x0028, bidi_bracket_type::close},
        {0x005B, 0x005D, bidi_bracket_type::open},
        {0x005D, 0x005B, bidi_bracket_type::close},
        {0x007B, 0x007D, bidi_bracket_type::open},
        {0x007D, 0x007B, bidi_bracket_type::close},
        {0x0F3A, 0x0F3B, bidi_bracket_type::open},
        {0x0F3B, 0x0F3A, bidi_bracket_type::close},
        {0x0F3C, 0x0F3D, bidi_bracket_type::open},
        {0x0F3D, 0x0F3C, bidi_bracket_type::close},
        {0x169B, 0x169C, bidi_bracket_type::open},
        {0x169C, 0x169B, bidi_bracket_type::close},
        {0x2045, 0x2046, bidi_bracket_type::open},
        {0x2046, 0x2045, bidi_bracket_type::close},
        {0x207D, 0x207E, bidi_bracket_type::open},
        {0x207E, 0x207D, bidi_bracket_type::close},
        {0x208D, 0x208E, bidi_bracket_type::open},
        {0x208E, 0x208D, bidi_bracket_type::close},
        {0x2308, 0x2309, bidi_bracket_type::open},
        {0x2309, 0x2308, bidi_bracket_type::close},
        {0x230A, 0x230B, bidi_bracket_type::open},
        {0x230B, 0x230A, bidi_bracket_type::close},
        {0x2329, 0x232A, bidi_bracket_type::open},
        {0x232A, 0x2329, bidi_bracket_type::close},
        {0x2768, 0x2769, bidi_bracket_type::open},
        {0x2769, 0x2768, bidi_bracket_type::close},
        {0x276A, 0x276B, bidi_bracket_type::open},
        {0x276B, 0x276A, bidi_bracket_type::close},
        {0x276C, 0x276D, bidi_bracket_type::open},
        {0x276D, 0x276C, bidi_bracket_type::close},
        {0x276E, 0x276F, bidi_bracket_type::open},
        {0x276F, 0x276E, bidi_bracket_type::close},
        {0x2770, 0x2771, bidi_bracket_type::open},
        {0x2771, 0x2770, bidi_bracket_type::close},
        {0x2772, 0x2773, bidi_bracket_type::open},
        {0x2773, 0x2772, bidi_bracket_type::close},
        {0x2774, 0x2775, bidi_bracket_type::open},
        {0x2775, 0x2774, bidi_bracket_type::close},
        {0x27C5, 0x27C6, bidi_bracket_type::open},
        {0x27C6, 0x27C5, bidi_bracket_type::close},
        {0x27E6, 0x27E7, bidi_bracket_type::open},
        {0x27E7, 0x27E6, bidi_bracket_type::close},
        {0x27E8, 0x27E9, bidi_bracket_type::open},
        {0x27E9, 0x27E8, bidi_bracket_type::close},
        {0x27EA, 0x27EB, bidi_bracket_type::open},
        {0x27EB, 0x27EA, bidi_bracket_type::close},
        {0x27EC, 0x27ED, bidi_bracket_type::open},
        {0x27ED, 0x27EC, bidi_bracket_type::close},
        {0x27EE, 0x27EF, bidi_bracket_type::open},
        {0x27EF, 0x27EE, bidi_bracket_type::close},
        {0x2983, 0x2984, bidi_bracket_type::open},
        {0x2984, 0x2983, bidi_bracket_type::close},
        {0x2985, 0x2986, bidi_bracket_type::open},
        {0x2986, 0x2985, bidi_bracket_type::close},
        {0x2987, 0x2988, bidi_bracket_type::open},
        {0x2988, 0x2987, bidi_bracket_type::close},
        {0x2989, 0x298A, bidi_bracket_type::open},
        {0x298A, 0x2989, bidi_bracket_type::close},
        {0x298B, 0x298C, bidi_bracket_type::open},
        {0x298C, 0x298B, bidi_bracket_type::close},
        {0x298D, 0x2990, bidi_bracket_type::open},
        {0x298E, 0x298F, bidi_bracket_type::close},
        {0x298F, 0x298E, bidi_bracket_type::open},
        {0x2990, 0x298D, bidi_bracket_type::close},
        {0x2991, 0x2992, bidi_bracket_type::open},
        {0x2992, 0x2991, bidi_bracket_type::close},
        {0x2993, 0x2994, bidi_bracket_type::open},
        {0x2994, 0x2993, bidi_bracket_type::close},
        {0x2995, 0x2996, bidi_bracket_type::open},
        {0x2996, 0x2995, bidi_bracket_type::close},
        {0x2997, 0x2998, bidi_bracket_type::open},
        {0x2998, 0x2997, bidi_bracket_type::close},
        {0x29D8, 0x29D9, bidi_bracket_type::open},
        {0x29D9, 0x29D8, bidi_bracket_type::close},
        {0x29DA, 0x29DB, bidi_bracket_type::open},
        {0x29DB, 0x29DA, bidi_bracket_type::close},
        {0x29FC, 0x29FD, bidi_bracket_type::open},
        {0x29FD, 0x29FC, bidi_bracket_type::close},
        {0x2E22, 0x2E23, bidi_bracket_type::open},
        {0x2E23, 0x2E22, bidi_bracket_type::close},
        {0x2E24, 0x2E25, bidi_bracket_type::open},
        {0x2E25, 0x2E24, bidi_bracket_type::close},
        {0x2E26, 0x2E27, bidi_bracket_type::open},
        {0x2E27, 0x2E26, bidi_bracket_type::close},
        {0x2E28, 0x2E29, bidi_bracket_type::open},
        {0x2E29, 0x2E28, bidi_bracket_type::close},
        {0x2E55, 0x2E56, bidi_bracket_type::open},
        {0x2E56, 0x2E55, bidi_bracket_type::close},
        {0x2E57, 0x2E58, bidi_bracket_type::open},
        {0x2E58, 0x2E57, bidi_bracket_type::close},
        {0x2E59, 0x2E5A, bidi_bracket_type::open},
        {0x2E5A, 0x2E59, bidi_bracket_type::close},
        {0x2E5B, 0x2E5C, bidi_bracket_type::open},
        {0x2E5C, 0x2E5B, bidi_bracket_type::close},
        {0x3008, 0x3009, bidi_bracket_type::open},
        {0x3009, 0x3008, bidi_bracket_type::close},
        {0x300A, 0x300B, bidi_bracket_type::open},
        {0x300B, 0x300A, bidi_bracket_type::close},
        {0x300C, 0x300D, bidi_bracket_type::open},
        {0x300D, 0x300C, bidi_bracket_type::close},
        {0x300E, 0x300F, bidi_bracket_type::open},
        {0x300F, 0x300E, bidi_bracket_type::close},
        {0x3010, 0x3011, bidi_bracket_type::open},
        {0x3011, 0x3010, bidi_bracket_type::close},
        {0x3014, 0x3015, bidi_bracket_type::open},
        {0x3015, 0x3014, bidi_bracket_type::close},
        {0x3016, 0x3017, bidi_bracket_type::open},
        {0x3017, 0x3016, bidi_bracket_type::close},
        {0x3018, 0x3019, bidi_bracket_type::open},
        {0x3019, 0x3018, bidi_bracket_type::close},
        {0x301A, 0x301B, bidi_bracket_type::open},
        {0x301B, 0x301A, bidi_bracket_type::close},
        {0xFE59, 0xFE5A, bidi_bracket_type::open},
        {0xFE5A, 0xFE59, bidi_bracket_type::close},
        {0xFE5B, 0xFE5C, bidi_bracket_type::open},
        {0xFE5C, 0xFE5B, bidi_bracket_type::close},
        {0xFE5D, 0xFE5E, bidi_bracket_type::open},
        {0xFE5E, 0xFE5D, bidi_bracket_type::close},
        {0xFF08, 0xFF09, bidi_bracket_type::open},
        {0xFF09, 0xFF08, bidi_bracket_type::close},
        {0xFF3B, 0xFF3D, bidi_bracket_type::open},
        {0xFF3D, 0xFF3B, bidi_bracket_type::close},
        {0xFF5B, 0xFF5D, bidi_bracket_type::open},
        {0xFF5D, 0xFF5B, bidi_bracket_type::close},
        {0xFF5F, 0xFF60, bidi_bracket_type::open},
        {0xFF60, 0xFF5F, bidi_bracket_type::close},
        {0xFF62, 0xFF63, bidi_bracket_type::open},
        {0xFF63, 0xFF62, bidi_bracket_type::close},
    }};

    auto const it = std::lower_bound(
        brackets.begin(), brackets.end(), bidi_bracket_data{cp},
        [](bidi_bracket_data lhs, bidi_bracket_data rhs){
            return lhs.cp_ < rhs.cp_;
        });
    if (it == brackets.end() || it->cp_ != cp)
        return bidi_bracket_data{0};
    return *it;
}

struct bidi_mirroring_data
{
    uint32_t cp_;
    int index_; // within bidi_mirroreds()
};

inline int bidi_mirroring(uint32_t cp)
{
    static std::array<bidi_mirroring_data, 428> const mirrorings = {{
        {0x0028, 1},
        {0x0029, 0},
        {0x003C, 3},
        {0x003E, 2},
        {0x005B, 5},
        {0x005D, 4},
        {0x007B, 7},
        {0x007D, 6},
        {0x00AB, 9},
        {0x00BB, 8},
        {0x0F3A, 11},
        {0x0F3B, 10},
        {0x0F3C, 13},
        {0x0F3D, 12},
        {0x169B, 15},
        {0x169C, 14},
        {0x2039, 17},
        {0x203A, 16},
        {0x2045, 19},
        {0x2046, 18},
        {0x207D, 21},
        {0x207E, 20},
        {0x208D, 23},
        {0x208E, 22},
        {0x2208, 27},
        {0x2209, 28},
        {0x220A, 29},
        {0x220B, 24},
        {0x220C, 25},
        {0x220D, 26},
        {0x2215, 245},
        {0x221F, 361},
        {0x2220, 217},
        {0x2221, 215},
        {0x2222, 216},
        {0x2224, 356},
        {0x223C, 37},
        {0x223D, 36},
        {0x2243, 107},
        {0x2245, 40},
        {0x224C, 39},
        {0x2252, 42},
        {0x2253, 41},
        {0x2254, 44},
        {0x2255, 43},
        {0x2264, 46},
        {0x2265, 45},
        {0x2266, 48},
        {0x2267, 47},
        {0x2268, 50},
        {0x2269, 49},
        {0x226A, 52},
        {0x226B, 51},
        {0x226E, 54},
        {0x226F, 53},
        {0x2270, 56},
        {0x2271, 55},
        {0x2272, 58},
        {0x2273, 57},
        {0x2274, 60},
        {0x2275, 59},
        {0x2276, 62},
        {0x2277, 61},
        {0x2278, 64},
        {0x2279, 63},
        {0x227A, 66},
        {0x227B, 65},
        {0x227C, 68},
        {0x227D, 67},
        {0x227E, 70},
        {0x227F, 69},
        {0x2280, 72},
        {0x2281, 71},
        {0x2282, 74},
        {0x2283, 73},
        {0x2284, 76},
        {0x2285, 75},
        {0x2286, 78},
        {0x2287, 77},
        {0x2288, 80},
        {0x2289, 79},
        {0x228A, 82},
        {0x228B, 81},
        {0x228F, 84},
        {0x2290, 83},
        {0x2291, 86},
        {0x2292, 85},
        {0x2298, 228},
        {0x22A2, 89},
        {0x22A3, 88},
        {0x22A6, 350},
        {0x22A8, 352},
        {0x22A9, 351},
        {0x22AB, 353},
        {0x22B0, 95},
        {0x22B1, 94},
        {0x22B2, 97},
        {0x22B3, 96},
        {0x22B4, 99},
        {0x22B5, 98},
        {0x22B6, 101},
        {0x22B7, 100},
        {0x22B8, 176},
        {0x22C9, 104},
        {0x22CA, 103},
        {0x22CB, 106},
        {0x22CC, 105},
        {0x22CD, 38},
        {0x22D0, 109},
        {0x22D1, 108},
        {0x22D6, 111},
        {0x22D7, 110},
        {0x22D8, 113},
        {0x22D9, 112},
        {0x22DA, 115},
        {0x22DB, 114},
        {0x22DC, 117},
        {0x22DD, 116},
        {0x22DE, 119},
        {0x22DF, 118},
        {0x22E0, 121},
        {0x22E1, 120},
        {0x22E2, 123},
        {0x22E3, 122},
        {0x22E4, 125},
        {0x22E5, 124},
        {0x22E6, 127},
        {0x22E7, 126},
        {0x22E8, 129},
        {0x22E9, 128},
        {0x22EA, 131},
        {0x22EB, 130},
        {0x22EC, 133},
        {0x22ED, 132},
        {0x22F0, 135},
        {0x22F1, 134},
        {0x22F2, 141},
        {0x22F3, 142},
        {0x22F4, 143},
        {0x22F6, 144},
        {0x22F7, 145},
        {0x22FA, 136},
        {0x22FB, 137},
        {0x22FC, 138},
        {0x22FD, 139},
        {0x22FE, 140},
        {0x2308, 147},
        {0x2309, 146},
        {0x230A, 149},
        {0x230B, 148},
        {0x2329, 151},
        {0x232A, 150},
        {0x2768, 153},
        {0x2769, 152},
        {0x276A, 155},
        {0x276B, 154},
        {0x276C, 157},
        {0x276D, 156},
        {0x276E, 159},
        {0x276F, 158},
        {0x2770, 161},
        {0x2771, 160},
        {0x2772, 163},
        {0x2773, 162},
        {0x2774, 165},
        {0x2775, 164},
        {0x27C3, 167},
        {0x27C4, 166},
        {0x27C5, 169},
        {0x27C6, 168},
        {0x27C8, 171},
        {0x27C9, 170},
        {0x27CB, 173},
        {0x27CD, 172},
        {0x27D5, 175},
        {0x27D6, 174},
        {0x27DC, 102},
        {0x27DD, 178},
        {0x27DE, 177},
        {0x27E2, 180},
        {0x27E3, 179},
        {0x27E4, 182},
        {0x27E5, 181},
        {0x27E6, 184},
        {0x27E7, 183},
        {0x27E8, 186},
        {0x27E9, 185},
        {0x27EA, 188},
        {0x27EB, 187},
        {0x27EC, 190},
        {0x27ED, 189},
        {0x27EE, 192},
        {0x27EF, 191},
        {0x2983, 194},
        {0x2984, 193},
        {0x2985, 196},
        {0x2986, 195},
        {0x2987, 198},
        {0x2988, 197},
        {0x2989, 200},
        {0x298A, 199},
        {0x298B, 202},
        {0x298C, 201},
        {0x298D, 206},
        {0x298E, 205},
        {0x298F, 204},
        {0x2990, 203},
        {0x2991, 208},
        {0x2992, 207},
        {0x2993, 210},
        {0x2994, 209},
        {0x2995, 212},
        {0x2996, 211},
        {0x2997, 214},
        {0x2998, 213},
        {0x299B, 33},
        {0x29A0, 34},
        {0x29A3, 32},
        {0x29A4, 219},
        {0x29A5, 218},
        {0x29A8, 221},
        {0x29A9, 220},
        {0x29AA, 223},
        {0x29AB, 222},
        {0x29AC, 225},
        {0x29AD, 224},
        {0x29AE, 227},
        {0x29AF, 226},
        {0x29B8, 87},
        {0x29C0, 230},
        {0x29C1, 229},
        {0x29C4, 232},
        {0x29C5, 231},
        {0x29CF, 234},
        {0x29D0, 233},
        {0x29D1, 236},
        {0x29D2, 235},
        {0x29D4, 238},
        {0x29D5, 237},
        {0x29D8, 240},
        {0x29D9, 239},
        {0x29DA, 242},
        {0x29DB, 241},
        {0x29E8, 244},
        {0x29E9, 243},
        {0x29F5, 30},
        {0x29F8, 247},
        {0x29F9, 246},
        {0x29FC, 249},
        {0x29FD, 248},
        {0x2A2B, 251},
        {0x2A2C, 250},
        {0x2A2D, 253},
        {0x2A2E, 252},
        {0x2A34, 255},
        {0x2A35, 254},
        {0x2A3C, 257},
        {0x2A3D, 256},
        {0x2A64, 259},
        {0x2A65, 258},
        {0x2A79, 261},
        {0x2A7A, 260},
        {0x2A7B, 263},
        {0x2A7C, 262},
        {0x2A7D, 265},
        {0x2A7E, 264},
        {0x2A7F, 267},
        {0x2A80, 266},
        {0x2A81, 269},
        {0x2A82, 268},
        {0x2A83, 271},
        {0x2A84, 270},
        {0x2A85, 273},
        {0x2A86, 272},
        {0x2A87, 275},
        {0x2A88, 274},
        {0x2A89, 277},
        {0x2A8A, 276},
        {0x2A8B, 279},
        {0x2A8C, 278},
        {0x2A8D, 281},
        {0x2A8E, 280},
        {0x2A8F, 283},
        {0x2A90, 282},
        {0x2A91, 285},
        {0x2A92, 284},
        {0x2A93, 287},
        {0x2A94, 286},
        {0x2A95, 289},
        {0x2A96, 288},
        {0x2A97, 291},
        {0x2A98, 290},
        {0x2A99, 293},
        {0x2A9A, 292},
        {0x2A9B, 295},
        {0x2A9C, 294},
        {0x2A9D, 297},
        {0x2A9E, 296},
        {0x2A9F, 299},
        {0x2AA0, 298},
        {0x2AA1, 301},
        {0x2AA2, 300},
        {0x2AA6, 303},
        {0x2AA7, 302},
        {0x2AA8, 305},
        {0x2AA9, 304},
        {0x2AAA, 307},
        {0x2AAB, 306},
        {0x2AAC, 309},
        {0x2AAD, 308},
        {0x2AAF, 311},
        {0x2AB0, 310},
        {0x2AB1, 313},
        {0x2AB2, 312},
        {0x2AB3, 315},
        {0x2AB4, 314},
        {0x2AB5, 317},
        {0x2AB6, 316},
        {0x2AB7, 319},
        {0x2AB8, 318},
        {0x2AB9, 321},
        {0x2ABA, 320},
        {0x2ABB, 323},
        {0x2ABC, 322},
        {0x2ABD, 325},
        {0x2ABE, 324},
        {0x2ABF, 327},
        {0x2AC0, 326},
        {0x2AC1, 329},
        {0x2AC2, 328},
        {0x2AC3, 331},
        {0x2AC4, 330},
        {0x2AC5, 333},
        {0x2AC6, 332},
        {0x2AC7, 335},
        {0x2AC8, 334},
        {0x2AC9, 337},
        {0x2ACA, 336},
        {0x2ACB, 339},
        {0x2ACC, 338},
        {0x2ACD, 341},
        {0x2ACE, 340},
        {0x2ACF, 343},
        {0x2AD0, 342},
        {0x2AD1, 345},
        {0x2AD2, 344},
        {0x2AD3, 347},
        {0x2AD4, 346},
        {0x2AD5, 349},
        {0x2AD6, 348},
        {0x2ADE, 90},
        {0x2AE3, 92},
        {0x2AE4, 91},
        {0x2AE5, 93},
        {0x2AEC, 355},
        {0x2AED, 354},
        {0x2AEE, 35},
        {0x2AF7, 358},
        {0x2AF8, 357},
        {0x2AF9, 360},
        {0x2AFA, 359},
        {0x2BFE, 31},
        {0x2E02, 363},
        {0x2E03, 362},
        {0x2E04, 365},
        {0x2E05, 364},
        {0x2E09, 367},
        {0x2E0A, 366},
        {0x2E0C, 369},
        {0x2E0D, 368},
        {0x2E1C, 371},
        {0x2E1D, 370},
        {0x2E20, 373},
        {0x2E21, 372},
        {0x2E22, 375},
        {0x2E23, 374},
        {0x2E24, 377},
        {0x2E25, 376},
        {0x2E26, 379},
        {0x2E27, 378},
        {0x2E28, 381},
        {0x2E29, 380},
        {0x2E55, 383},
        {0x2E56, 382},
        {0x2E57, 385},
        {0x2E58, 384},
        {0x2E59, 387},
        {0x2E5A, 386},
        {0x2E5B, 389},
        {0x2E5C, 388},
        {0x3008, 391},
        {0x3009, 390},
        {0x300A, 393},
        {0x300B, 392},
        {0x300C, 395},
        {0x300D, 394},
        {0x300E, 397},
        {0x300F, 396},
        {0x3010, 399},
        {0x3011, 398},
        {0x3014, 401},
        {0x3015, 400},
        {0x3016, 403},
        {0x3017, 402},
        {0x3018, 405},
        {0x3019, 404},
        {0x301A, 407},
        {0x301B, 406},
        {0xFE59, 409},
        {0xFE5A, 408},
        {0xFE5B, 411},
        {0xFE5C, 410},
        {0xFE5D, 413},
        {0xFE5E, 412},
        {0xFE64, 415},
        {0xFE65, 414},
        {0xFF08, 417},
        {0xFF09, 416},
        {0xFF1C, 419},
        {0xFF1E, 418},
        {0xFF3B, 421},
        {0xFF3D, 420},
        {0xFF5B, 423},
        {0xFF5D, 422},
        {0xFF5F, 425},
        {0xFF60, 424},
        {0xFF62, 427},
        {0xFF63, 426},
    }};

    auto const it = std::lower_bound(
        mirrorings.begin(), mirrorings.end(), bidi_mirroring_data{cp},
        [](bidi_mirroring_data lhs, bidi_mirroring_data rhs){
            return lhs.cp_ < rhs.cp_;
        });
    if (it == mirrorings.end() || it->cp_ != cp)
        return -1;
    return it->index_;
}

inline std::array<uint32_t, 428> const & bidi_mirroreds()
{
    static std::array<uint32_t, 428> const retval = {{
        0x0028,
        0x0029,
        0x003C,
        0x003E,
        0x005B,
        0x005D,
        0x007B,
        0x007D,
        0x00AB,
        0x00BB,
        0x0F3A,
        0x0F3B,
        0x0F3C,
        0x0F3D,
        0x169B,
        0x169C,
        0x2039,
        0x203A,
        0x2045,
        0x2046,
        0x207D,
        0x207E,
        0x208D,
        0x208E,
        0x2208,
        0x2209,
        0x220A,
        0x220B,
        0x220C,
        0x220D,
        0x2215,
        0x221F,
        0x2220,
        0x2221,
        0x2222,
        0x2224,
        0x223C,
        0x223D,
        0x2243,
        0x2245,
        0x224C,
        0x2252,
        0x2253,
        0x2254,
        0x2255,
        0x2264,
        0x2265,
        0x2266,
        0x2267,
        0x2268,
        0x2269,
        0x226A,
        0x226B,
        0x226E,
        0x226F,
        0x2270,
        0x2271,
        0x2272,
        0x2273,
        0x2274,
        0x2275,
        0x2276,
        0x2277,
        0x2278,
        0x2279,
        0x227A,
        0x227B,
        0x227C,
        0x227D,
        0x227E,
        0x227F,
        0x2280,
        0x2281,
        0x2282,
        0x2283,
        0x2284,
        0x2285,
        0x2286,
        0x2287,
        0x2288,
        0x2289,
        0x228A,
        0x228B,
        0x228F,
        0x2290,
        0x2291,
        0x2292,
        0x2298,
        0x22A2,
        0x22A3,
        0x22A6,
        0x22A8,
        0x22A9,
        0x22AB,
        0x22B0,
        0x22B1,
        0x22B2,
        0x22B3,
        0x22B4,
        0x22B5,
        0x22B6,
        0x22B7,
        0x22B8,
        0x22C9,
        0x22CA,
        0x22CB,
        0x22CC,
        0x22CD,
        0x22D0,
        0x22D1,
        0x22D6,
        0x22D7,
        0x22D8,
        0x22D9,
        0x22DA,
        0x22DB,
        0x22DC,
        0x22DD,
        0x22DE,
        0x22DF,
        0x22E0,
        0x22E1,
        0x22E2,
        0x22E3,
        0x22E4,
        0x22E5,
        0x22E6,
        0x22E7,
        0x22E8,
        0x22E9,
        0x22EA,
        0x22EB,
        0x22EC,
        0x22ED,
        0x22F0,
        0x22F1,
        0x22F2,
        0x22F3,
        0x22F4,
        0x22F6,
        0x22F7,
        0x22FA,
        0x22FB,
        0x22FC,
        0x22FD,
        0x22FE,
        0x2308,
        0x2309,
        0x230A,
        0x230B,
        0x2329,
        0x232A,
        0x2768,
        0x2769,
        0x276A,
        0x276B,
        0x276C,
        0x276D,
        0x276E,
        0x276F,
        0x2770,
        0x2771,
        0x2772,
        0x2773,
        0x2774,
        0x2775,
        0x27C3,
        0x27C4,
        0x27C5,
        0x27C6,
        0x27C8,
        0x27C9,
        0x27CB,
        0x27CD,
        0x27D5,
        0x27D6,
        0x27DC,
        0x27DD,
        0x27DE,
        0x27E2,
        0x27E3,
        0x27E4,
        0x27E5,
        0x27E6,
        0x27E7,
        0x27E8,
        0x27E9,
        0x27EA,
        0x27EB,
        0x27EC,
        0x27ED,
        0x27EE,
        0x27EF,
        0x2983,
        0x2984,
        0x2985,
        0x2986,
        0x2987,
        0x2988,
        0x2989,
        0x298A,
        0x298B,
        0x298C,
        0x298D,
        0x298E,
        0x298F,
        0x2990,
        0x2991,
        0x2992,
        0x2993,
        0x2994,
        0x2995,
        0x2996,
        0x2997,
        0x2998,
        0x299B,
        0x29A0,
        0x29A3,
        0x29A4,
        0x29A5,
        0x29A8,
        0x29A9,
        0x29AA,
        0x29AB,
        0x29AC,
        0x29AD,
        0x29AE,
        0x29AF,
        0x29B8,
        0x29C0,
        0x29C1,
        0x29C4,
        0x29C5,
        0x29CF,
        0x29D0,
        0x29D1,
        0x29D2,
        0x29D4,
        0x29D5,
        0x29D8,
        0x29D9,
        0x29DA,
        0x29DB,
        0x29E8,
        0x29E9,
        0x29F5,
        0x29F8,
        0x29F9,
        0x29FC,
        0x29FD,
        0x2A2B,
        0x2A2C,
        0x2A2D,
        0x2A2E,
        0x2A34,
        0x2A35,
        0x2A3C,
        0x2A3D,
        0x2A64,
        0x2A65,
        0x2A79,
        0x2A7A,
        0x2A7B,
        0x2A7C,
        0x2A7D,
        0x2A7E,
        0x2A7F,
        0x2A80,
        0x2A81,
        0x2A82,
        0x2A83,
        0x2A84,
        0x2A85,
        0x2A86,
        0x2A87,
        0x2A88,
        0x2A89,
        0x2A8A,
        0x2A8B,
        0x2A8C,
        0x2A8D,
        0x2A8E,
        0x2A8F,
        0x2A90,
        0x2A91,
        0x2A92,
        0x2A93,
        0x2A94,
        0x2A95,
        0x2A96,
        0x2A97,
        0x2A98,
        0x2A99,
        0x2A9A,
        0x2A9B,
        0x2A9C,
        0x2A9D,
        0x2A9E,
        0x2A9F,
        0x2AA0,
        0x2AA1,
        0x2AA2,
        0x2AA6,
        0x2AA7,
        0x2AA8,
        0x2AA9,
        0x2AAA,
        0x2AAB,
        0x2AAC,
        0x2AAD,
        0x2AAF,
        0x2AB0,
        0x2AB1,
        0x2AB2,
        0x2AB3,
        0x2AB4,
        0x2AB5,
        0x2AB6,
        0x2AB7,
        0x2AB8,
        0x2AB9,
        0x2ABA,
        0x2ABB,
        0x2ABC,
        0x2ABD,
        0x2ABE,
        0x2ABF,
        0x2AC0,
        0x2AC1,
        0x2AC2,
        0x2AC3,
        0x2AC4,
        0x2AC5,
        0x2AC6,
        0x2AC7,
        0x2AC8,
        0x2AC9,
        0x2ACA,
        0x2ACB,
        0x2ACC,
        0x2ACD,
        0x2ACE,
        0x2ACF,
        0x2AD0,
        0x2AD1,
        0x2AD2,
        0x2AD3,
        0x2AD4,
        0x2AD5,
        0x2AD6,
        0x2ADE,
        0x2AE3,
        0x2AE4,
        0x2AE5,
        0x2AEC,
        0x2AED,
        0x2AEE,
        0x2AF7,
        0x2AF8,
        0x2AF9,
        0x2AFA,
        0x2BFE,
        0x2E02,
        0x2E03,
        0x2E04,
        0x2E05,
        0x2E09,
        0x2E0A,
        0x2E0C,
        0x2E0D,
        0x2E1C,
        0x2E1D,
        0x2E20,
        0x2E21,
        0x2E22,
        0x2E23,
        0x2E24,
        0x2E25,
        0x2E26,
        0x2E27,
        0x2E28,
        0x2E29,
        0x2E55,
        0x2E56,
        0x2E57,
        0x2E58,
        0x2E59,
        0x2E5A,
        0x2E5B,
        0x2E5C,
        0x3008,
        0x3009,
        0x300A,
        0x300B,
        0x300C,
        0x300D,
        0x300E,
        0x300F,
        0x3010,
        0x3011,
        0x3014,
        0x3015,
        0x3016,
        0x3017,
        0x3018,
        0x3019,
        0x301A,
        0x301B,
        0xFE59,
        0xFE5A,
        0xFE5B,
        0xFE5C,
        0xFE5D,
        0xFE5E,
        0xFE64,
        0xFE65,
        0xFF08,
        0xFF09,
        0xFF1C,
        0xFF1E,
        0xFF3B,
        0xFF3D,
        0xFF5B,
        0xFF5D,
        0xFF5F,
        0xFF60,
        0xFF62,
        0xFF63,
    }};
    return retval;
}

}}}

#endif
