#include "handler.hpp"


namespace xlog
{
    Handler& get_handler() { return stdhdlr; }
    Handler& get_handler(const string_t& name)
    {
        if (name == "" || name == "std")
            return stdhdlr;
        if (!Handler::handlers.count(name))
            Handler(name);
        return Handler::handlers.at(name);
    }

    Handler::Handler(const string_t& name)
        : name(name)
    {
        handlers.insert({ name, this });
    }

    Handler& Handler::set_min(uchar mn)
    {
        if (mn > max) std::swap(mn, max);
        min = mn;
        return *this;
    }

    Handler& Handler::set_max(uchar mx)
    {
        if (mx < min) std::swap(mx, min);
        max = mx;
        return *this;
    }

    Handler& Handler::set_filter(const string_t& fmt_name)
    {
        format_name = fmt_name;
        return *this;
    }

    Handler& Handler::set_filter(const string_t& filt_name)
    {
        filter_name = filt_name;
        return *this;
    }

    Handler& Handler::add_buffer(buffer_t buf)
    {
        lstream.add_buffer(buf);
        return *this;
    }

    Handler& Handler::add_file(const fs::path& path)
    {
        std::ofstream ofs(path);
        add_buffer(ofs.rdbuf());
        return *this;
    }

    Handler& Handler::add_buffers(ilist<buffer_t> bufs)
    {
        for (buffer_t buf : bufs)
            add_buffer(buf);
        return *this;
    }

    Handler& Handler::add_files(ilist<fs::path> paths)
    {
        for (fs::path path : paths)
            add_file(path);
        return *this;
    }

    bool Handler::handle(Record& rcd)
    {
        if (!filter()(rcd)) return false;
        lstream.write(rcd.get_msg());
        return true;
    }
}
