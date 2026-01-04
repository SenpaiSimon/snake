#pragma once

namespace Object {
class IObject {
public:
    IObject() = default;
    virtual ~IObject() = default;
    virtual void Update() = 0;
    virtual void Render() = 0;

    virtual bool ToBeDeleted() { return false; }
};
} // namespace Object