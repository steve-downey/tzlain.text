
// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/save_load_table.hpp>
#include <boost/text/data/all.hpp>

#include <boost/filesystem.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

collation_table make_save_load_table()
{
    if (!exists(boost::filesystem::path("be_standard.table"))) {
        string const table_str(data::be::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "be::standard_collation_tailoring()", error, warning);
        save_table(table, "be_standard.table.0");
        boost::filesystem::rename("be_standard.table.0", "be_standard.table");
    }
    return load_table("be_standard.table");
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, be_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0415),
        std::vector<uint32_t>(1, 0x0451),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0451),
        std::vector<uint32_t>(1, 0x0401),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0451),
        std::vector<uint32_t>(1, 0x0401),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0443),
        std::vector<uint32_t>(1, 0x045e),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x045e),
        std::vector<uint32_t>(1, 0x040e),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x045e),
        std::vector<uint32_t>(1, 0x040e),
        table(), collation_strength::secondary),
        0);
}
