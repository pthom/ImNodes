#pragma once


#ifdef IMNODES_PYBIND
#include <string>
#include <pybind11/pybind11.h>

namespace py = pybind11;
#endif


namespace ImNodes
{
#ifdef IMNODES_PYBIND
    using SlotTitle = std::string;
    using Any = py::object *;
#else
    using SlotTitle = const char *;
    using Any = void *;
#endif
}
