
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
    string const table_str(data::und::emoji_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "und::emoji_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("und_emoji.table"))) {
        string const table_str(data::und::emoji_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "und::emoji_collation_tailoring()", error, warning);
        save_table(table, "und_emoji.table.2");
        boost::filesystem::rename("und_emoji.table.2", "und_emoji.table");
    }
    return load_table("und_emoji.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, und_emoji_001_000)
{
}
