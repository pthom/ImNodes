#pragma once

#include "ImNodes/ImNodes.h"
#include "ImNodes/cpp/ImNodesStdTypes.h"

#include <optional>


namespace ImNodes
{
    struct AnyWrapper    { Any Value = {}; };
    struct BoolWrapper   { bool Value = {}; };

    struct ConnectionSlot
    {
        AnyWrapper  Node  = {};
        std::string SlotTitle = {};

        inline bool operator==(const ConnectionSlot & other) {
            auto& self = *this;
            return ( (self.SlotTitle == other.SlotTitle) && (self.Node.Value == other.Node.Value) );
        }
    };

    struct ConnectionInfo
    {
        ConnectionSlot InputNode;
        ConnectionSlot OutputNode;

        inline bool operator==(const ConnectionInfo & other) {
            auto& self = *this;
            return ((self.InputNode == other.InputNode) && (self.OutputNode == other.OutputNode));
        }
    };

    struct PendingConnection
    {
        ConnectionSlot Slot;
        int SlotKind;
    };

    /// Begin rendering of node in a graph. Render node content when returns `true`.
    IMGUI_API bool BeginNode(AnyWrapper node, ImVec2* pos, BoolWrapper* selected);

    /// Specified node will be positioned at the mouse cursor on next frame. Call when new node is created.
    IMGUI_API void AutoPositionNode(AnyWrapper node);

    /// Returns a value when a new connection is made.
    /// Must be called at id scope created by BeginNode().
    IMGUI_API std::optional<ConnectionInfo> GetNewConnection();

    /// Get information of connection that is being made and has only one end connected. Returns true when pending connection exists, false otherwise.
    IMGUI_API std::optional<PendingConnection> GetPendingConnection();

    /// Render a connection. Returns `true` when connection is present, `false` if it is deleted.
    IMGUI_API bool Connection(const ConnectionInfo& connectionInfo);

}