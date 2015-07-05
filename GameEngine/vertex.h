#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& pos) {
		this->pos = pos;
	}

	inline glm::vec3* getPos() { return &pos; }
private:
	glm::vec3 pos;
};