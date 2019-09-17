#ifndef BOOST_TEXT_DETAIL_ICU_NORMALIZE_HPP
#define BOOST_TEXT_DETAIL_ICU_NORMALIZE_HPP

#include <boost/text/transcode_algorithm.hpp>
#include <boost/text/detail/icu/normalizer2impl.hpp>
#include <boost/text/detail/icu/norm2_nfc_data.hpp>
#include <boost/text/detail/icu/norm2_nfkc_data.hpp>


namespace boost { namespace text { namespace detail { namespace icu {

    inline Normalizer2Impl & nfc_norm()
    {
        static Normalizer2Impl retval;
        static bool once = true;
        if (once) {
            retval.init(
                norm2_nfc_data_indexes,
                &norm2_nfc_data_trie,
                norm2_nfc_data_extraData,
                norm2_nfc_data_smallFCD);
            once = false;
        }
        return retval;
    }

    inline Normalizer2Impl & nfkc_norm()
    {
        static Normalizer2Impl retval;
        static bool once = true;
        if (once) {
            retval.init(
                norm2_nfkc_data_indexes,
                &norm2_nfkc_data_trie,
                norm2_nfkc_data_extraData,
                norm2_nfkc_data_smallFCD);
            once = false;
        }
        return retval;
    }

    template<typename String>
    struct string_appender
    {
        explicit string_appender(String & s) : s_(&s) {}

        template<typename CharIter>
        void append(CharIter bytes, int32_t n)
        {
            s_->insert(s_->end(), bytes, bytes + n);
        }

    private:
        String * s_;
    };

    template<typename OutIter>
    struct iter_appender
    {
        explicit iter_appender(OutIter out) : out_(out) {}

        template<typename CharIter>
        void append(CharIter bytes, int32_t n)
        {
            out_ = std::copy((char const *)bytes, (char const *)bytes + n, out_);
        }

    private:
        OutIter out_;
    };

    template<typename CharIter, typename Sentinel, typename String>
    void utf8_normalize_to_nfc_append(CharIter first, Sentinel last, String & s)
    {
        nfc_norm().composeUTF8<false, true>(
            first, last, string_appender<String>(s));
    }

    template<typename Iter, typename Sentinel>
    void
    utf16_normalize_to_nfc_append(Iter first, Sentinel last, UnicodeString & s)
    {
        ReorderingBuffer<utf16_appender<UnicodeString>> buffer(
            nfc_norm(), utf16_appender<UnicodeString>(s));
        nfc_norm().compose<false, true>(first, last, buffer);
    }

    template<typename Iter, typename Sentinel>
    Iter
    utf16_normalize_to_nfd_append(Iter first, Sentinel last, UnicodeString & s)
    {
        ReorderingBuffer<utf16_appender<UnicodeString>> buffer(
            nfc_norm(), utf16_appender<UnicodeString>(s));
        return nfc_norm().decompose<true>(first, last, buffer);
    }

    template<typename CharIter, typename Sentinel, typename String>
    void utf8_normalize_to_nfkc_append(CharIter first, Sentinel last, String & s)
    {
        nfkc_norm().composeUTF8<false, true>(
            first, last, string_appender<String>(s));
    }

    template<typename Iter, typename Sentinel>
    void
    utf16_normalize_to_nfkc_append(Iter first, Sentinel last, UnicodeString & s)
    {
        ReorderingBuffer<utf16_appender<UnicodeString>> buffer(
            nfkc_norm(), utf16_appender<UnicodeString>(s));
        nfkc_norm().compose<false, true>(first, last, buffer);
    }

    template<typename Iter, typename Sentinel>
    Iter
    utf16_normalize_to_nfkd_append(Iter first, Sentinel last, UnicodeString & s)
    {
        ReorderingBuffer<utf16_appender<UnicodeString>> buffer(
            nfkc_norm(), utf16_appender<UnicodeString>(s));
        return nfkc_norm().decompose<true>(first, last, buffer);
    }

    template<typename CharIter, typename Sentinel, typename String>
    void utf8_normalize_to_fcc_append(CharIter first, Sentinel last, String & s)
    {
        nfc_norm().composeUTF8<true, true>(
            first, last, string_appender<String>(s));
    }

    template<typename Iter, typename Sentinel>
    void
    utf16_normalize_to_fcc_append(Iter first, Sentinel last, UnicodeString & s)
    {
        ReorderingBuffer<utf16_appender<UnicodeString>> buffer(
            nfc_norm(), utf16_appender<UnicodeString>(s));
        nfc_norm().compose<true, true>(first, last, buffer);
    }

}}}}

#endif
