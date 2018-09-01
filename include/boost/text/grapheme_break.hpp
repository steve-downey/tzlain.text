#ifndef BOOST_TEXT_GRAPHEME_BREAK_HPP
#define BOOST_TEXT_GRAPHEME_BREAK_HPP

#include <boost/text/algorithm.hpp>
#include <boost/text/lazy_segment_range.hpp>
#include <boost/text/utility.hpp>

#include <boost/assert.hpp>

#include <array>
#include <unordered_map>

#include <stdint.h>


namespace boost { namespace text {

    /** The grapheme properties outlined in Unicode 10. */
    enum class grapheme_property {
        Other,
        CR,
        LF,
        Control,
        Extend,
        Prepend,
        SpacingMark,
        L,
        V,
        T,
        LV,
        LVT,
        Regional_Indicator,
        E_Base,
        E_Modifier,
        ZWJ,
        Glue_After_Zwj,
        E_Base_GAZ
    };

    namespace detail {
        struct grapheme_prop_interval
        {
            uint32_t lo_;
            uint32_t hi_;
            grapheme_property prop_;
        };

        inline bool operator<(
            grapheme_prop_interval lhs, grapheme_prop_interval rhs) noexcept
        {
            return lhs.hi_ <= rhs.lo_;
        }

        BOOST_TEXT_DECL std::array<grapheme_prop_interval, 3> const &
        make_grapheme_prop_intervals();
        BOOST_TEXT_DECL std::unordered_map<uint32_t, grapheme_property>
        make_grapheme_prop_map();
    }

    /** Returns the grapheme property associated with code point \a cp. */
    inline grapheme_property grapheme_prop(uint32_t cp) noexcept
    {
        static auto const map = detail::make_grapheme_prop_map();
        static auto const intervals = detail::make_grapheme_prop_intervals();

        auto const it = map.find(cp);
        if (it == map.end()) {
            auto const it2 = std::lower_bound(
                intervals.begin(),
                intervals.end(),
                detail::grapheme_prop_interval{cp, cp + 1});
            if (it2 == intervals.end() || cp < it2->lo_ || it2->hi_ <= cp)
                return grapheme_property::Other;
            return it2->prop_;
        }
        return it->second;
    }

    namespace detail {
        inline bool skippable(grapheme_property prop) noexcept
        {
            return prop == grapheme_property::Extend;
        }

        enum class grapheme_break_emoji_state_t {
            none,
            first_emoji, // Indicates that prop points to an odd-count
                         // emoji.
            second_emoji // Indicates that prop points to an even-count
                         // emoji.
        };

        template<typename CPIter>
        struct grapheme_break_state
        {
            CPIter it;
            bool it_points_to_prev = false;

            grapheme_property prev_prop;
            grapheme_property prop;

            grapheme_break_emoji_state_t emoji_state;
        };

        template<typename CPIter>
        grapheme_break_state<CPIter> next(grapheme_break_state<CPIter> state)
        {
            ++state.it;
            state.prev_prop = state.prop;
            return state;
        }

        template<typename CPIter>
        grapheme_break_state<CPIter> prev(grapheme_break_state<CPIter> state)
        {
            if (!state.it_points_to_prev)
                --state.it;
            state.it_points_to_prev = false;
            state.prop = state.prev_prop;
            return state;
        }

        inline bool table_grapheme_break(
            grapheme_property lhs, grapheme_property rhs) noexcept
        {
            // Note that RI.RI was changed to '1' since that case is handled in
            // the grapheme break FSM.

            // clang-format off
// See chart at http://www.unicode.org/Public/UCD/latest/ucd/auxiliary/GraphemeBreakTest.html.
constexpr std::array<std::array<bool, 18>, 18> grapheme_breaks = {{
//   Other CR LF Ctrl Ext Pre SpcMk L  V  T  LV LVT RI E_Bse E_Mod ZWJ GAZ EBG
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  1,  1}}, // Other
    {{1,   1, 0, 1,   1,  1,  1,    1, 1, 1, 1, 1,  1, 1,    1,    1,  1,  1}}, // CR
    {{1,   1, 1, 1,   1,  1,  1,    1, 1, 1, 1, 1,  1, 1,    1,    1,  1,  1}}, // LF
                             
    {{1,   1, 1, 1,   1,  1,  1,    1, 1, 1, 1, 1,  1, 1,    1,    1,  1,  1}}, // Control
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  1,  1}}, // Extend
    {{0,   1, 1, 1,   0,  0,  0,    0, 0, 0, 0, 0,  0, 0,    0,    0,  0,  0}}, // Prepend
                             
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  1,  1}}, // SpacingMark
    {{1,   1, 1, 1,   0,  1,  0,    0, 0, 1, 0, 0,  1, 1,    1,    0,  1,  1}}, // L
    {{1,   1, 1, 1,   0,  1,  0,    1, 0, 0, 1, 1,  1, 1,    1,    0,  1,  1}}, // V
                             
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 0, 1, 1,  1, 1,    1,    0,  1,  1}}, // T
    {{1,   1, 1, 1,   0,  1,  0,    1, 0, 0, 1, 1,  1, 1,    1,    0,  1,  1}}, // LV
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 0, 1, 1,  1, 1,    1,    0,  1,  1}}, // LVT
                             
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  1,  1}}, // Regional_Indicator
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    0,    0,  1,  1}}, // E_Base
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  1,  1}}, // E_Modifier

    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  0,  0}}, // ZWJ
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    1,    0,  1,  1}}, // Glue_After_Zwj
    {{1,   1, 1, 1,   0,  1,  0,    1, 1, 1, 1, 1,  1, 1,    0,    0,  1,  1}}, // E_Base_GAZ
}};
            // clang-format on
            auto const lhs_int = static_cast<int>(lhs);
            auto const rhs_int = static_cast<int>(rhs);
            return grapheme_breaks[lhs_int][rhs_int];
        }

        template<typename CPIter, typename Sentinel>
        grapheme_break_state<CPIter> skip_forward(
            grapheme_break_state<CPIter> state, CPIter first, Sentinel last)
        {
            if (state.it != first &&
                (state.prev_prop == grapheme_property::E_Base ||
                 state.prev_prop == grapheme_property::E_Base_GAZ) &&
                skippable(state.prop)) {
                auto temp_it =
                    find_if_not(std::next(state.it), last, [](uint32_t cp) {
                        return skippable(grapheme_prop(cp));
                    });
                if (temp_it != last &&
                    grapheme_prop(*temp_it) == grapheme_property::E_Modifier) {
                    auto const temp_prop = grapheme_prop(*temp_it);
                    state.it = temp_it;
                    state.prop = temp_prop;
                }
            }
            return state;
        }
    }

    /** Finds the nearest grapheme break at or before before <code>it</code>.
        If <code>it == first</code>, that is returned.  Otherwise, the first
        code point of the grapheme that <code>it</code> is within is returned
        (even if <code>it</code> is already at the first code point of a
        grapheme). */
    template<typename CPIter, typename Sentinel>
    auto prev_grapheme_break(CPIter first, CPIter it, Sentinel last) noexcept
        -> detail::cp_iter_ret_t<CPIter, CPIter>
    {
        if (it == first)
            return it;

        if (it == last && --it == first)
            return it;

        detail::grapheme_break_state<CPIter> state;
        state.it = it;
        state.prop = grapheme_prop(*state.it);
        state.prev_prop = grapheme_prop(*std::prev(state.it));
        state.emoji_state = detail::grapheme_break_emoji_state_t::none;

        // GB10
        auto skip = [](detail::grapheme_break_state<CPIter> state,
                       CPIter first) {
            if (state.prop == grapheme_property::E_Modifier &&
                detail::skippable(state.prev_prop)) {
                auto temp_it =
                    find_if_not_backward(first, state.it, [](uint32_t cp) {
                        return detail::skippable(grapheme_prop(cp));
                    });
                if (temp_it == state.it)
                    return state;
                auto temp_prev_prop = grapheme_prop(*temp_it);
                if (temp_prev_prop == grapheme_property::E_Base ||
                    temp_prev_prop == grapheme_property::E_Base_GAZ) {
                    state.it = temp_it;
                    state.it_points_to_prev = true;
                    state.prev_prop = temp_prev_prop;
                }
            }
            return state;
        };

        for (; state.it != first; state = prev(state)) {
            state.prev_prop = grapheme_prop(*std::prev(state.it));

            // When we see an RI, back up to the first RI so we can see what
            // emoji state we're supposed to be in here.
            if (state.emoji_state ==
                    detail::grapheme_break_emoji_state_t::none &&
                state.prop == grapheme_property::Regional_Indicator) {
                int ris_before = 0;
                find_if_not_backward(
                    first, state.it, [&ris_before](uint32_t cp) {
                        bool const ri = grapheme_prop(cp) ==
                                        grapheme_property::Regional_Indicator;
                        if (ri)
                            ++ris_before;
                        return ri;
                    });
                state.emoji_state =
                    (ris_before % 2 == 0)
                        ? detail::grapheme_break_emoji_state_t::first_emoji
                        : detail::grapheme_break_emoji_state_t::second_emoji;
            }

            // If we end up breaking durign this iteration, we want the break
            // to show up after the skip, so that the skippable CPs go with
            // the CP before them.  This is to maintain symmetry with
            // next_grapheme_break().
            auto after_skip_it = state.it;

            // Puting this here means not having to do it explicitly below
            // between prev_prop and prop (and transitively, between prop and
            // next_prop).
            state = skip(state, first);

            if (state.emoji_state ==
                detail::grapheme_break_emoji_state_t::first_emoji) {
                if (state.prev_prop == grapheme_property::Regional_Indicator) {
                    state.emoji_state =
                        detail::grapheme_break_emoji_state_t::second_emoji;
                    return after_skip_it;
                } else {
                    state.emoji_state =
                        detail::grapheme_break_emoji_state_t::none;
                }
            } else if (
                state.emoji_state ==
                    detail::grapheme_break_emoji_state_t::second_emoji &&
                state.prev_prop == grapheme_property::Regional_Indicator) {
                state.emoji_state =
                    detail::grapheme_break_emoji_state_t::first_emoji;
                continue;
            }

            if (detail::table_grapheme_break(state.prev_prop, state.prop))
                return after_skip_it;
        }

        return first;
    }

    /** Finds the next word break after <code>first</code>.  This will be the
        first code point after the current word, or <code>last</code> if no
        next word exists.

        \pre <code>first</code> is at the beginning of a word. */
    template<typename CPIter, typename Sentinel>
    auto next_grapheme_break(CPIter first, Sentinel last) noexcept
        -> detail::cp_iter_ret_t<CPIter, CPIter>
    {
        if (first == last)
            return first;

        detail::grapheme_break_state<CPIter> state;
        state.it = first;

        if (++state.it == last)
            return state.it;

        state.prev_prop = grapheme_prop(*std::prev(state.it));
        state.prop = grapheme_prop(*state.it);

        state.emoji_state =
            state.prev_prop == grapheme_property::Regional_Indicator
                ? detail::grapheme_break_emoji_state_t::first_emoji
                : detail::grapheme_break_emoji_state_t::none;

        for (; state.it != last; state = next(state)) {
            state.prop = grapheme_prop(*state.it);

            // GB10
            state = detail::skip_forward(state, first, last);
            if (state.it == last)
                return state.it;

            if (state.emoji_state ==
                detail::grapheme_break_emoji_state_t::first_emoji) {
                if (state.prop == grapheme_property::Regional_Indicator) {
                    state.emoji_state =
                        detail::grapheme_break_emoji_state_t::none;
                    continue;
                } else {
                    state.emoji_state =
                        detail::grapheme_break_emoji_state_t::none;
                }
            } else if (state.prop == grapheme_property::Regional_Indicator) {
                state.emoji_state =
                    detail::grapheme_break_emoji_state_t::first_emoji;
            }

            if (detail::table_grapheme_break(state.prev_prop, state.prop))
                return state.it;
        }

        return state.it;
    }

    /** Finds the nearest grapheme break at or before before <code>it</code>.
        If <code>it == range.begin()</code>, that is returned.  Otherwise, the
        first code point of the grapheme that <code>it</code> is within is
        returned (even if <code>it</code> is already at the first code point
        of a grapheme). */
    template<typename CPRange, typename CPIter>
    auto prev_grapheme_break(CPRange & range, CPIter it) noexcept
        -> detail::iterator_t<CPRange>
    {
        return prev_grapheme_break(std::begin(range), it, std::end(range));
    }

    /** Finds the next grapheme break after <code>it</code>.  This will be the
        first code point after the current grapheme, or
        <code>range.end()</code> if no next grapheme exists.

        \pre <code>it</code> is at the beginning of a grapheme. */
    template<typename CPRange, typename CPIter>
    auto next_grapheme_break(CPRange & range, CPIter it) noexcept
        -> detail::iterator_t<CPRange>
    {
        return next_grapheme_break(it, std::end(range));
    }

    namespace detail {
        template<typename CPIter, typename Sentinel>
        struct next_grapheme_callable
        {
            CPIter operator()(CPIter it, Sentinel last) const noexcept
            {
                return next_grapheme_break(it, last);
            }
        };

        template<typename CPIter>
        struct prev_grapheme_callable
        {
            CPIter operator()(CPIter first, CPIter it, CPIter last) const
                noexcept
            {
                return prev_grapheme_break(first, it, last);
            }
        };
    }

    /** Returns the bounds of the grapheme that <code>it</code> lies within. */
    template<typename CPIter, typename Sentinel>
    cp_range<CPIter> grapheme(CPIter first, CPIter it, Sentinel last) noexcept
    {
        first = prev_grapheme_break(first, it, last);
        return cp_range<CPIter>{first, next_grapheme_break(first, last)};
    }

    /** Returns the bounds of the grapheme that <code>it</code> lies
        within. */
    template<typename CPRange, typename CPIter>
    auto grapheme(CPRange & range, CPIter it) noexcept
        -> cp_range<detail::iterator_t<CPRange>>
    {
        auto first =
            prev_grapheme_break(std::begin(range), it, std::end(range));
        return cp_range<CPIter>{first, next_grapheme_break(first, range.end())};
    }

    /** Returns a lazy range of the code point ranges delimiting graphemes in
        <code>[first, last)</code>. */
    template<typename CPIter, typename Sentinel>
    lazy_segment_range<
        CPIter,
        Sentinel,
        detail::next_grapheme_callable<CPIter, Sentinel>>
    graphemes(CPIter first, Sentinel last) noexcept
    {
        detail::next_grapheme_callable<CPIter, Sentinel> next;
        return {std::move(next), {first, last}, {last}};
    }

    /** Returns a lazy range of the code point ranges delimiting graphemes in
        <code>range</code>. */
    template<typename CPRange>
    auto graphemes(CPRange & range) noexcept -> lazy_segment_range<
        detail::iterator_t<CPRange>,
        detail::sentinel_t<CPRange>,
        detail::next_grapheme_callable<
            detail::iterator_t<CPRange>,
            detail::sentinel_t<CPRange>>>
    {
        detail::next_grapheme_callable<
            detail::iterator_t<CPRange>,
            detail::sentinel_t<CPRange>>
            next;
        return {std::move(next),
                {std::begin(range), std::end(range)},
                {std::end(range)}};
    }

    /** Returns a lazy range of the code point ranges delimiting graphemes in
        <code>[first, last)</code>, in reverse. */
    template<typename CPIter>
    lazy_segment_range<
        CPIter,
        CPIter,
        detail::prev_grapheme_callable<CPIter>,
        cp_range<CPIter>,
        detail::const_reverse_lazy_segment_iterator,
        true>
    reversed_graphemes(CPIter first, CPIter last) noexcept
    {
        detail::prev_grapheme_callable<CPIter> prev;
        return {std::move(prev), {first, last, last}, {first, first, last}};
    }

    /** Returns a lazy range of the code point ranges delimiting graphemes in
        <code>range</code>, in reverse. */
    template<typename CPRange>
    auto reversed_graphemes(CPRange & range) noexcept -> lazy_segment_range<
        detail::iterator_t<CPRange>,
        detail::sentinel_t<CPRange>,
        detail::prev_grapheme_callable<detail::iterator_t<CPRange>>,
        cp_range<detail::iterator_t<CPRange>>,
        detail::const_reverse_lazy_segment_iterator,
        true>
    {
        detail::prev_grapheme_callable<detail::iterator_t<CPRange>> prev;
        return {std::move(prev),
                {std::begin(range), std::end(range), std::end(range)},
                {std::begin(range), std::begin(range), std::end(range)}};
    }

}}

#endif
