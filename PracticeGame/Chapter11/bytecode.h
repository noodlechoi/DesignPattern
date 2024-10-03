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
			// 피연산자 실행
			double left = left_->evaluate();
			double right = rigjt_->evaluate();

			// 더하기
			return left + right;
		}
	};
}