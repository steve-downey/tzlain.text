
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
    if (!exists(boost::filesystem::path("chr_standard.table"))) {
        string const table_str(data::chr::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "chr::standard_collation_tailoring()", error, warning);
        save_table(table, "chr_standard.table.0");
        boost::filesystem::rename("chr_standard.table.0", "chr_standard.table");
    }
    return load_table("chr_standard.table");
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, chr_standard_000_001)
{
}
