#include "ImNodes/cpp/ImNodesEzStdLib.h"


namespace ImNodes
{
namespace Ez
{

ContextAddress CreateContextWrapper()
{
    return (ContextAddress)CreateContext();
}

void FreeContextWrapper(ContextAddress ctx)
{
    FreeContext((Context *)ctx);
}

void SetContextWrapper(ContextAddress ctx)
{
    SetContext((Context *)ctx);
}


bool BeginNode(const ConnectionSlot& slot, ImVec2* pos, BoolWrapper* selected)
{
    bool r = BeginNode(slot.Node.Value, slot.SlotTitle.c_str(), pos, &selected->Value);
    return r;
}


}
}