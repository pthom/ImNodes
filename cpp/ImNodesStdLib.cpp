#include "ImNodes/cpp/ImNodesStdLib.h"


namespace ImNodes
{
    bool BeginNode(AnyWrapper node, ImVec2* pos, BoolWrapper* selected)
    {
        bool r = BeginNode(node.Value, pos, &selected->Value);
        return r;
    }

    void AutoPositionNode(AnyWrapper node)
    {
        AutoPositionNode(node.Value);
    }

    std::optional<ConnectionInfo> GetNewConnection()
    {
        void* input_node;
        void* output_node;
        const char* input_slot_title;
        const char* output_slot_title;
        bool r = GetNewConnection(&input_node, &input_slot_title, &output_node, &output_slot_title);

        if (!r)
            return std::nullopt;
        else
        {
            ConnectionInfo c;
            c.InputNode.Node.Value = (Any)input_node;
            c.OutputNode.Node.Value = (Any)output_node;
            c.InputNode.SlotTitle = input_slot_title;
            c.OutputNode.SlotTitle = output_slot_title;
            return c;
        }
    }

    std::optional<PendingConnection> GetPendingConnection()
    {
        void* node_id;
        const char* slot_title;
        int slot_kind;
        bool r = GetPendingConnection(&node_id, &slot_title, &slot_kind);
        if (!r)
            return std::nullopt;
        else
        {
            PendingConnection p;
            p.Slot.SlotTitle = slot_title;
            p.Slot.Node.Value = (Any)node_id;
            p.SlotKind = slot_kind;
            return p;
        }
    }

    bool Connection(const ConnectionInfo& connectionInfo)
    {
        bool r = Connection(
            connectionInfo.InputNode.Node.Value,
            connectionInfo.InputNode.SlotTitle.c_str(),
            connectionInfo.OutputNode.Node.Value,
            connectionInfo.OutputNode.SlotTitle.c_str()
            );
        return r;
    }



}