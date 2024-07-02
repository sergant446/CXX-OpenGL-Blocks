#include "VertexBuffer.hpp"

namespace Engine
{
    VertexBuffer::VertexBuffer(GLsizei Size, const void* Data, GLenum Usage)
    {
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, Size, Data, Usage);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    }

    VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &m_VBO); }

    void VertexBuffer::Bind() { glBindBuffer(GL_ARRAY_BUFFER, m_VBO); }
    void VertexBuffer::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
}
