#pragma once
#include <GL/glew.h>
typedef unsigned int uint;

namespace Engine
{
    class VertexBuffer
    {
    public:
        VertexBuffer(GLsizei Size, const void* Data, GLenum Usage);
        ~VertexBuffer();
        void Bind();
        void Unbind();
    private:
        uint m_VBO;
    };
}
