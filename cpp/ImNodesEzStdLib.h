#pragma once

#include "ImNodes/ImNodesEz.h"
#include "ImNodes/cpp/ImNodesStdLib.h"

namespace ImNodes
{
namespace Ez
{

using ContextAddress = std::uintptr_t;

// pybind11 fails spectacularly with opaque types...
IMGUI_API ContextAddress CreateContextWrapper();
IMGUI_API void FreeContextWrapper(ContextAddress ctx);
IMGUI_API void SetContextWrapper(ContextAddress ctx);

/// Begin rendering of node in a graph. Render node content when returns `true`.
IMGUI_API bool BeginNode(const ConnectionSlot& slot, ImVec2* pos, BoolWrapper* selected);


}
}