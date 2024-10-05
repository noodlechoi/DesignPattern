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
	int getHealth(int winzard) { return 0; }
	int getWisdom(int winzard) { return 0; }
	int getAgility(int winzard) { return 0; }
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
		INST_GET_HEALTH = 0X05,
		INST_GET_WISDOM = 0X06,
		INST_GET_AGILITY = 0X07,
		INST_ADD = 0X08,
	};

	void assert(bool) {}

	class VM
	{
	private:
		static const int MAX_STACK = 128;
		int stackSize_;
		int stack_[MAX_STACK];
	public:
		VM() : stackSize_{} {}
		void push(int value)
		{
			// ���� �����÷� �˻�
			assert(stackSize_ < MAX_STACK);
			stack_[stackSize_++] = value;
		}
		int pop()
		{
			// ��� �ִ��� Ȯ��
			assert(stackSize_ > 0);
			return stack_[--stackSize_];
		}

		void interpret(char bytecode[], int size)
		{
			for (int i = 0; i < size; ++i) {
				char instruction = bytecode[i];
				switch (instruction) {
				case INST_GET_HEALTH:
					int wizard = pop();
					push(getHealth(wizard));
					break;
				case INST_GET_WISDOM:
					int wizard = pop();
					push(getWisdom(wizard));
					break;
				case INST_GET_AGILITY:
					int wizard = pop();
					push(getAgility(wizard));
					break;
				case INST_SET_HEALTH:
					int amount = pop();
					int wizard = pop();
					setHealth(wizard, amount);
					break;
				case INST_SET_WISDOM:
					int amount = pop();
					int wizard = pop();
					setWisdom(wizard, amount);
					break;
				case INST_SET_AGILITY:
					int amount = pop();
					int wizard = pop();
					setAgility(wizard, amount);
					break;
				case INST_SET_SOUND:
					playSound(pop());
					break;
				case INST_SET_PARICLES:
					spawnParticles(pop());
					break;
				case INST_ADD: {
					int b = pop();
					int a = pop();
					push(a + b);
					break;
				}
				default:
					break;
				}
			}
		}
	};
}