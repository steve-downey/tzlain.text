
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
    string const table_str(data::kn::standard_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "kn::standard_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("kn_standard.table"))) {
        string const table_str(data::kn::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "kn::standard_collation_tailoring()", error, warning);
        save_table(table, "kn_standard.table.0");
        boost::filesystem::rename("kn_standard.table.0", "kn_standard.table");
    }
    return load_table("kn_standard.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, kn_standard_000_001)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0c94);
    auto const rel = std::vector<uint32_t>(1, 0x0c82);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0c82);
    auto const rel = std::vector<uint32_t>(1, 0x0c83);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0c83);
    auto const rel = std::vector<uint32_t>(1, 0x0cf1);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0cf1);
    auto const rel = std::vector<uint32_t>(1, 0x0cf2);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    }
}
