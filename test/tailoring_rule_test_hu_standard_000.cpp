
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
    string const table_str(data::hu::standard_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "hu::standard_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("hu_standard.table"))) {
        string const table_str(data::hu::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "hu::standard_collation_tailoring()", error, warning);
        save_table(table, "hu_standard.table.0");
        boost::filesystem::rename("hu_standard.table.0", "hu_standard.table");
    }
    return load_table("hu_standard.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, hu_standard_000_001)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0043);
    auto const rel = std::vector<uint32_t>{0x0063, 0x0073};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0063, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0043, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x0043, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0043, 0x0053};
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
    auto const res = std::vector<uint32_t>(1, 0x0044);
    auto const rel = std::vector<uint32_t>{0x0064, 0x007a};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0064, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0044, 0x007a};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0044, 0x005a};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x005a};
    auto const rel = std::vector<uint32_t>{0x0064, 0x007a, 0x0073};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0064, 0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0044, 0x007a, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0044, 0x005a, 0x0053};
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
    auto const res = std::vector<uint32_t>(1, 0x0047);
    auto const rel = std::vector<uint32_t>{0x0067, 0x0079};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0067, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0047, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x0047, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0047, 0x0059};
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
    auto const res = std::vector<uint32_t>(1, 0x004c);
    auto const rel = std::vector<uint32_t>{0x006c, 0x0079};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x006c, 0x0079};
    auto const rel = std::vector<uint32_t>{0x004c, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x004c, 0x0079};
    auto const rel = std::vector<uint32_t>{0x004c, 0x0059};
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
    auto const rel = std::vector<uint32_t>{0x006e, 0x0079};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x006e, 0x0079};
    auto const rel = std::vector<uint32_t>{0x004e, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x004e, 0x0079};
    auto const rel = std::vector<uint32_t>{0x004e, 0x0059};
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
    auto const res = std::vector<uint32_t>(1, 0x0053);
    auto const rel = std::vector<uint32_t>{0x0073, 0x007a};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0073, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0053, 0x007a};
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
    auto const res = std::vector<uint32_t>{0x0053, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0053, 0x005a};
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
    auto const res = std::vector<uint32_t>(1, 0x0054);
    auto const rel = std::vector<uint32_t>{0x0074, 0x0079};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0074, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0054, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x0054, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0054, 0x0059};
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
    auto const res = std::vector<uint32_t>(1, 0x005a);
    auto const rel = std::vector<uint32_t>{0x007a, 0x0073};
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x005a, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x005a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x005a, 0x0053};
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
    auto const res = std::vector<uint32_t>(1, 0x004f);
    auto const rel = std::vector<uint32_t>(1, 0x00f6);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x00f6);
    auto const rel = std::vector<uint32_t>(1, 0x00d6);
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
    auto const res = std::vector<uint32_t>(1, 0x00d6);
    auto const rel = std::vector<uint32_t>(1, 0x0151);
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
    auto const res = std::vector<uint32_t>(1, 0x0151);
    auto const rel = std::vector<uint32_t>(1, 0x0150);
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
    auto const res = std::vector<uint32_t>(1, 0x0055);
    auto const rel = std::vector<uint32_t>(1, 0x00fc);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
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
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0063, 0x0073, 0x0063, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0063, 0x0063, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x0043, 0x0073, 0x0063, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0043, 0x0063, 0x0073};
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

TEST(tailoring, hu_standard_000_002)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0043, 0x0053, 0x0043, 0x0053};
    auto const rel = std::vector<uint32_t>{0x0043, 0x0043, 0x0053};
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
    auto const res = std::vector<uint32_t>{0x0064, 0x007a, 0x0064, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0064, 0x0064, 0x007a};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x007a, 0x0064, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0044, 0x0064, 0x007a};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x005a, 0x0044, 0x005a};
    auto const rel = std::vector<uint32_t>{0x0044, 0x0044, 0x005a};
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
    auto const res = std::vector<uint32_t>{0x0064, 0x007a, 0x0073, 0x0064, 0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0064, 0x0064, 0x007a, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x007a, 0x0073, 0x0064, 0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x0044, 0x0064, 0x007a, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x0044, 0x005a, 0x0053, 0x0044, 0x005a, 0x0053};
    auto const rel = std::vector<uint32_t>{0x0044, 0x0044, 0x005a, 0x0053};
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
    auto const res = std::vector<uint32_t>{0x0067, 0x0079, 0x0067, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0067, 0x0067, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x0047, 0x0079, 0x0067, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0047, 0x0067, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x0047, 0x0059, 0x0047, 0x0059};
    auto const rel = std::vector<uint32_t>{0x0047, 0x0047, 0x0059};
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
    auto const res = std::vector<uint32_t>{0x006c, 0x0079, 0x006c, 0x0079};
    auto const rel = std::vector<uint32_t>{0x006c, 0x006c, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x004c, 0x0079, 0x006c, 0x0079};
    auto const rel = std::vector<uint32_t>{0x004c, 0x006c, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x004c, 0x0059, 0x004c, 0x0059};
    auto const rel = std::vector<uint32_t>{0x004c, 0x004c, 0x0059};
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
    auto const res = std::vector<uint32_t>{0x006e, 0x0079, 0x006e, 0x0079};
    auto const rel = std::vector<uint32_t>{0x006e, 0x006e, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x004e, 0x0079, 0x006e, 0x0079};
    auto const rel = std::vector<uint32_t>{0x004e, 0x006e, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x004e, 0x0059, 0x004e, 0x0059};
    auto const rel = std::vector<uint32_t>{0x004e, 0x004e, 0x0059};
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
    auto const res = std::vector<uint32_t>{0x0073, 0x007a, 0x0073, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0073, 0x0073, 0x007a};
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
    auto const res = std::vector<uint32_t>{0x0053, 0x007a, 0x0073, 0x007a};
    auto const rel = std::vector<uint32_t>{0x0053, 0x0073, 0x007a};
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
    auto const res = std::vector<uint32_t>{0x0053, 0x005a, 0x0053, 0x005a};
    auto const rel = std::vector<uint32_t>{0x0053, 0x0053, 0x005a};
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
    auto const res = std::vector<uint32_t>{0x0074, 0x0079, 0x0074, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0074, 0x0074, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x0054, 0x0079, 0x0074, 0x0079};
    auto const rel = std::vector<uint32_t>{0x0054, 0x0074, 0x0079};
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
    auto const res = std::vector<uint32_t>{0x0054, 0x0059, 0x0054, 0x0059};
    auto const rel = std::vector<uint32_t>{0x0054, 0x0054, 0x0059};
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
    auto const res = std::vector<uint32_t>{0x007a, 0x0073, 0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x007a, 0x007a, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x005a, 0x0073, 0x007a, 0x0073};
    auto const rel = std::vector<uint32_t>{0x005a, 0x007a, 0x0073};
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
    auto const res = std::vector<uint32_t>{0x005a, 0x0053, 0x005a, 0x0053};
    auto const rel = std::vector<uint32_t>{0x005a, 0x005a, 0x0053};
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
