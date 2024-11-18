#pragma once

namespace dirtyFlag
{
	class Mesh {};
	const int MAX_CHILDREN = 5;

	class Transform
	{
	public:
		static Transform origin();
		Transform combine(Transform& other);
	};

	// ��Ƽ �÷��� ���� ����
	class GraphNode	// �ֻ��� ���(��Ʈ)
	{
	private:
		Transform local_;
		Mesh* mesh_;
		GraphNode* children_[MAX_CHILDREN];
		int numChildren_;
	public:
		GraphNode(Mesh* mesh) : mesh_{mesh}, local_{Transform::origin()} {}
		void render(Transform parentWorld)	// graph->render(Transform::origin) => ��Ʈ ��� ȣ��
		{
			Transform world = local_.combine(parentWorld);
			if (mesh_) renderMesh(mesh_, world);
			for (int i = 0; i < numChildren_; ++i) {
				children_[i]->render(world);
			}
		}
	};

	void renderMesh(Mesh* mesh, Transform transform) {} // �޽ø� �׸��� �۾�
}