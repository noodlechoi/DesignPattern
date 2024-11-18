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

	// 더티 플래그 적용 이전
	class GraphNode	// 최상위 노드(루트)
	{
	private:
		Transform world_;
		bool dirty_;
		Transform local_;
		Mesh* mesh_;
		GraphNode* children_[MAX_CHILDREN];
		int numChildren_;
	public:
		GraphNode(Mesh* mesh) : mesh_{ mesh }, local_{ Transform::origin() }, dirty_{ true } {}
		void render(Transform parentWorld, bool dirty)
		{
			dirty |= dirty_;
			if (dirty) {
				world_ = local_.combine(parentWorld);
				dirty_ = false;
			}

			if (mesh_) renderMesh(mesh_, world_);

			for (int i = 0; i < numChildren_; ++i) {
				children_[i]->render(world_, dirty);
			}
		}

		void setTransform(Transform local)
		{
			local_ = local;
			dirty_ = true;
		}
	};

	void renderMesh(Mesh* mesh, Transform transform) {} // 메시를 그리는 작업
}