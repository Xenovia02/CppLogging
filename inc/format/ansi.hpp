#ifndef X_LOG_FORMAT_ANSIFMT_HPP
#define X_LOG_FORMAT_ANSIFMT_HPP

#include "fwd_declares.hpp"


namespace xlog
{
    namespace dtl
    {
        constexpr const char* c_ansi_prefix = "\033[";
#ifdef CPP20
        constexpr std::string ansi_pref(c_ansi_prefix);
#else
        const std::string ansi_pref(c_ansi_prefix);
#endif
    }

    enum struct AnsiOpts : short
    {
        reset          = 0,
        bold_on        = 1,
        faint          = 2,
        italic         = 3,
        uline          = 4,
        slow_blink     = 5,
        rapid_blink    = 6,
        invert         = 7,
        hide           = 8,
        strike         = 9,
        def_font       = 10,
        gothic         = 20,
        dbl_uline      = 21, // or not bold
        norm_intensity = 22,
        no_italic      = 23,
        no_uline       = 24,
        no_blink       = 25,
        not_reversed   = 27,
        reveal         = 28,
        no_strike      = 29,
        fg_black       = 30,
        fg_red         = 31,
        fg_green       = 32,
        fg_yellow      = 33,
        fg_blue        = 34,
        fg_magenta     = 35,
        fg_cyan        = 36,
        fg_white       = 37,
        def_fg_clr     = 39,
        bg_black       = 40,
        bg_red         = 41,
        bg_green       = 42,
        bg_yellow      = 43,
        bg_blue        = 44,
        bg_magenta     = 45,
        bg_cyan        = 46,
        bg_white       = 47,
        def_bg_clr     = 49,
        oline          = 53,
        no_oline       = 55,
        super          = 73,
        sub            = 74,
        no_sup_or_sub  = 75,
    };

    std::string operator "" _ansi(const char*);
    std::string ansi_format(const char*);
    std::string ansi_format(AnsiOpts);
    void ansi_format(std::string&);
    void ansi_format(std::string&, AnsiOpts);
}

#endif