
// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#ifndef LIMIT_TESTING_FOR_CI
#include <boost/text/save_load_table.hpp>

#include <boost/filesystem.hpp>
#endif

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

collation_table make_save_load_table()
{
#ifdef LIMIT_TESTING_FOR_CI
    string const table_str(data::fi::traditional_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "fi::traditional_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("fi_traditional.table"))) {
        string const table_str(data::fi::traditional_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "fi::traditional_collation_tailoring()", error, warning);
        save_table(table, "fi_traditional.table.0");
        boost::filesystem::rename("fi_traditional.table.0", "fi_traditional.table");
    }
    return load_table("fi_traditional.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, fi_traditional_000_001)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0044);
    auto const rel = std::vector<uint32_t>(1, 0x00f0);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x00f0);
    auto const rel = std::vector<uint32_t>(1, 0x00d0);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x00d0);
    auto const rel = std::vector<uint32_t>(1, 0x0111);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0111);
    auto const rel = std::vector<uint32_t>(1, 0x0110);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x004e);
    auto const rel = std::vector<uint32_t>(1, 0x014b);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x014b);
    auto const rel = std::vector<uint32_t>(1, 0x014a);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0054, 0x0068};
    auto const rel = std::vector<uint32_t>(1, 0x00fe);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x00fe, 0x0068};
    auto const rel = std::vector<uint32_t>(1, 0x00de);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0056);
    auto const rel = std::vector<uint32_t>(1, 0x0077);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0077);
    auto const rel = std::vector<uint32_t>(1, 0x0057);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0059);
    auto const rel = std::vector<uint32_t>(1, 0x00fc);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x00fc);
    auto const rel = std::vector<uint32_t>(1, 0x00dc);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x00dc);
    auto const rel = std::vector<uint32_t>(1, 0x0171);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0171);
    auto const rel = std::vector<uint32_t>(1, 0x0170);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    }
}
