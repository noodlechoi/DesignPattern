#pragma once
namespace EXPRESSION
{
	class Expression
	{
	public:
		virtual ~Expression() {}
		virtual double evaluate() = 0;
	};

	class NumberExpression : public Expression
	{
	private:
		double value_;
	public:
		NumberExpression(double value) : value_{value} {}
		virtual double evaluate() override { return value_; }
	};

	class AdditionExpression : public Expression
	{
	private:
		Expression* left_;
		Expression* rigjt_;
	public:
		AdditionExpression(Expression* left, Expression* right) : left_{left}, rigjt_{right} {}
		virtual double evaluate() override
		{
			// �ǿ����� ����
			double left = left_->evaluate();
			double right = rigjt_->evaluate();

			// ���ϱ�
			return left + right;
		}
	};
}

namespace VM
{
	// ���� API
	void setHealth(int winzard, int amount) {}
	void setWisdom(int winzard, int amount) {}
	void setAgility(int winzard, int amount) {}
	void playSound(int soundId) {}
	void spawnParticles(int particleType) {}
	static int SOUND_BANG = 0;
	static int PARCICLE_FLAME = 0;

	// ������ ���ڵ�
	enum Instruction
	{
		INST_SET_HEALTH = 0X00,
		INST_SET_WISDOM = 0X01,
		INST_SET_AGILITY = 0X02,
		INST_SET_SOUND = 0X03,
		INST_SET_PARICLES = 0X04,
	};

	class VM
	{
	public:
		void interpret(char bytecode[], int size)
		{
			for (int i = 0; i < size; ++i) {
				char instruction = bytecode[i];
				switch (instruction) {
				case INST_SET_HEALTH:
					setHealth(0, 100);
					break;
				case INST_SET_WISDOM:
					setWisdom(0, 100);
					break;
				case INST_SET_AGILITY:
					setAgility(0, 100);
					break;
				case INST_SET_SOUND:
					playSound(SOUND_BANG);
					break;
				case INST_SET_PARICLES:
					spawnParticles(PARCICLE_FLAME);
					break;
				default:
					break;
				}
			}
		}
	};
}