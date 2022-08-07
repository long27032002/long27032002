/*
*							PROJECT  DATA STRUCTURE & ALGORITHM ET2100
* 
*	Topic 5: Building a library that allows to calculate expression values with Reserve polish rotation
* 
*	-------------------------------------------------------------------------
*	|	  MSSV		|	  Ho va ten thanh vien		|						|
*	|---------------+-------------------------------+-----------------------|
*	|	20203437	|	      HA TUAN HUNG			|						|
*	|---------------+-------------------------------+-----------------------|
*	|	20203412	|		 NGUYEN THU HIEN		|						|
*	|---------------+-------------------------------+-----------------------|
*	|	20200366	|	   NGUYEN NHU HAI LONG		|						|
*	|---------------+-------------------------------+-----------------------|
*	|	20203506	|		  HA TUAN MINH			|						|
*	-------------------------------------------------------------------------
*	version 4.0 - 19/07/2022
*/
#pragma once
#ifndef _RPN_H_
#define _RPN_H_

#include <iostream>
#include <string>
#include <cmath>

#define FAIL_CALCULATE -1

/// <summary>
/// The operator_t is constant array.
/// </summary>
const char operator_t[10] = { '-', '+', '*', '/', '^', '.', '(' , ')', '!' };


class Divide_To_Zero : public std::runtime_error
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Divide_To_Zero"/> class.
	/// </summary>
	Divide_To_Zero() : std::runtime_error("\n Error divide to zero. \n") {};
};


class Less_Than_Zero : public std::runtime_error
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Less_than_Zero"/> class.
	/// </summary>
	Less_Than_Zero() : std::runtime_error("\n Error less than zero. \n") {};
};


class Syntax_Error : public std::runtime_error
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Syntax_Error"/> class.
	/// </summary>
	Syntax_Error() : std::runtime_error("\n Syntax error! \n") {};
};


/// <summary>
/// Exceptions the handling.
/// </summary>
/// <param name="expression">The expression.</param>
void Exception_Handling(std::string expression)
{
	try
	{

		for (size_t i = 1; i <= 9; i++)
			if (expression.front() == operator_t[i])
				throw Syntax_Error();

		for (size_t i = 0; i <= 7; i++)
			if (expression.back() == operator_t[i])
				throw Syntax_Error();


		int count	= 0;
		size_t _len = expression.length();
		for (size_t i = 0; i < _len; i++)
		{
			if (expression.at(i) == operator_t[6]) count++;
			if (expression.at(i) == operator_t[7]) count--;
		}
		if (count)	throw Syntax_Error();


		char chr[3] = "";
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				bool condition = false;
				condition |= ((i == 0) && ((j == 0) || (j == 6)));
				condition |= ((i != 5) && (j == 0));
				condition |= (((i == 8) || (i == 7)) && ((j != 5) && (j != 6)));
				condition |= (((i != 5 || i != 7) || (i != 8)) && (j == 6));
				if (condition) continue;

				sprintf_s(chr, "%c%c", operator_t[i], operator_t[j]);
				if (strstr(expression.c_str(), chr) != NULL)
					throw Syntax_Error();
			}
		}

	}

	catch (const Syntax_Error& exception)
	{
		std::cout << exception.what();
		abort();
	}
};


/// <summary>
/// Struct Node
/// </summary>
struct Node
{
	/// <summary>
	/// The variable std::string type.
	/// </summary>
	std::string  str_t;

	/// <summary>
	/// The flag to check str_t string:
	/// Flag_Check = 1  : str_t is operator.
	/// Flag_check = 0  : str_t is a double value.
	/// Flag_Check = -1 : str_t is a variable.
	/// </summary>
	int	 Flag_Check;

	/// <summary>
	/// The pointer point to next struct Node.
	/// </summary>
	struct Node* next;

	/// <summary>
	/// Initializes a new instance of the <see cref="Node"/> struct.
	/// </summary>
	Node()
	{
		str_t		= "";
		Flag_Check  = 0;
		next		= NULL;
	};

	/// <summary>
	/// Initializes a new instance of the <see cref="Node"/> struct.
	/// </summary>
	/// <param name="temp_t">The parameter std::string type.</param>
	Node(const std::string temp_t)
	{
		str_t		= temp_t;
		Flag_Check	= 0;
		next		= NULL;
	};

	/// <summary>
	/// Initializes a new instance of the <see cref="Node"/> struct.
	/// </summary>
	/// <param name="temp_t">The parameter std::string type.</param>
	/// <param name="_flag">The flag_check.</param>
	Node(const std::string temp_t, const int _flag)
	{
		str_t		= temp_t;
		Flag_Check	= _flag;
		next		= NULL;
	};

	/// <summary>
	/// Finalizes an instance of the <see cref="Node"/> struct.
	/// </summary>
	~Node()
	{
		str_t		= "";
		Flag_Check	= 0;
		next		= NULL;
	}
};

template<typename DATA_TYPE>
struct NodeType 
{
	/// <summary>
	/// The temporary data.
	/// </summary>
	DATA_TYPE Temp_Data;

	/// <summary>
	/// The next pointer.
	/// </summary>
	NodeType* next;

	/// <summary>
	/// Initializes a new instance of the <see cref="NodeType{DATA_TYPE}"/> struct.
	/// </summary>
	NodeType()
	{
		next = NULL;
	};

	/// <summary>
	/// Initializes a new instance of the <see cref="NodeType{DATA_TYPE}"/> struct.
	/// </summary>
	/// <param name="_value">The value.</param>
	NodeType(const double _value = 0.0)
	{
		Temp_Data	= _value;
		next		= NULL;
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="NodeType{DATA_TYPE}"/> struct.
	/// </summary>
	/// <param name="_str">The string.</param>
	/// <param name="_flag">The flag.</param>
	NodeType(const std::string _str, const int _flag)
	{
		Node *temp	= new Node(_str, _flag);
		Temp_Data	= *temp;
		next		= NULL;
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="NodeType{DATA_TYPE}"/> class.
	/// </summary>
	~NodeType()
	{
		next = NULL;
	}
};

template<typename DATA_TYPE>
struct Stack
{
	/// <summary>
	/// The pointer point to the first element of the stack.
	/// </summary>
	NodeType<DATA_TYPE>* head;

	/// <summary>
	/// Initializes a new instance of the <see cref="Stack<DATA_TYPE>"/> struct.
	/// </summary>
	Stack()
	{
		this->head = NULL;
	};

	/// <summary>
	/// Determines whether this instance is empty.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
	/// </returns>
	bool Is_Empty()
	{
		return (this->head == NULL) ? true : false;
	}

	/// <summary>
	/// Stacks the push.
	/// </summary>
	/// <param name="_str">The string.</param>
	/// <param name="_flag">The flag.</param>
	void Stack_Push(const std::string _str, const int _flag) 
	{
		NodeType<Node>* tmp = new NodeType<Node>(_str, _flag);

		if (Is_Empty())
		{
			this->head = tmp;
		}
		else {
			tmp->next  = (this->head);
			this->head = tmp;
		}
	}

	/// <summary>
	/// Add an element to the top of the stack.
	/// </summary>
	/// <param name="_value">The value.</param>
	void Stack_Push(const double _value) 
	{
		NodeType<DATA_TYPE>* tmp = new NodeType<DATA_TYPE>(_value);

		if (Is_Empty())
		{
			this->head = tmp;
		}
		else {
			tmp->next  = this->head;
			this->head = tmp;
		}
	}

	/// <summary>
	/// Delete the element to the top of the stack.
	/// </summary>
	/// <returns></returns>
	DATA_TYPE Stack_Pop()
	{
		if (Is_Empty())
		{
			return DATA_TYPE();
		}
		else
		{
			DATA_TYPE Data_return			= this->head->Temp_Data;
			NodeType<DATA_TYPE>* dlt_ptr	= this->head;
			this->head						= this->head->next;
			delete dlt_ptr;
			return Data_return;
		}
	}

	/// <summary>
	/// Show the element to the top of the stack.
	/// </summary>
	/// <returns></returns>
	DATA_TYPE Stack_Peek()
	{
		return head->Temp_Data;
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="Stack<DATA_TYPE>"/> class.
	/// </summary>
	~Stack()
	{
		while (!Is_Empty()) 
		{
			this->Stack_Pop();
		}
	};
};

/// <summary>
/// Determines whether the specified c is operator.
/// </summary>
/// <param name="c">The character.</param>
/// <returns>
///   <c>true</c> if the specified c is operator; otherwise, <c>false</c>.
/// </returns>
bool Is_Operator(char c) 
{
	for (size_t i = 0; i < 9; i++)
	{
		if ((operator_t[i] == c) && (i != 5))
		{
			return true;
		};
	};
	return false;
}

/// <summary>
/// Operator precedence.
/// </summary>
/// <param name="c"> Operator.</param>
/// <returns>int</returns>
int Priority(char c) {
	if (c == '+' || c == '-')
	{
		return 1;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '^')
	{
		return 3;
	}
	else if (c == '!')
	{
		return 4;
	}
	else if (c == '(' || c == ')')
	{
		return 5;
	}
	else {
		return -1;
	};
};


/// <summary>
/// Reserves polish notation.
/// </summary>
/// <param name="expression">The expression.</param>
/// <param name="_RPN">The RPN.</param>
void Reserve_Polish_Notation(std::string expression, Stack<Node>& _RPN)
{

	Exception_Handling(expression);

	Stack<Node>		operator_st;
	Node			operand_t;
	size_t			len = expression.length();

	for (size_t i = 0; i < len; i++) {
		if (Is_Operator(expression[i]))
		{
			if (i == 0 && (expression[i] == operator_t[0]))
			{
				operand_t.str_t.append(1, operator_t[0]);
				operand_t.Flag_Check = 0;
				continue;
			}
			else if (i > 0)
			{
				if (Is_Operator(expression[i - 1]) && (expression[i] == operator_t[0]))
				{
					operand_t.str_t.append(1, operator_t[0]);
					operand_t.Flag_Check = 0;
					continue;
				}
			}

			if (!operand_t.str_t.empty())
			{
				_RPN.Stack_Push(operand_t.str_t, operand_t.Flag_Check);
				operand_t.~Node();
			}

			if (expression[i] == operator_t[6])
			{
				operator_st.Stack_Push(std::string(1, expression[i]), 1);
			}
			else if (expression[i] == operator_t[7])
			{
				while (!operator_st.Is_Empty())
				{
					if (operator_st.Stack_Peek().str_t[0] != operator_t[6]) {
						std::string tmp_1 = operator_st.Stack_Pop().str_t;
						_RPN.Stack_Push(tmp_1, 1);
					}
					else
					{
						operator_st.Stack_Pop();
						break;
					}
				}

			}
			else
			{
				while ((!operator_st.Is_Empty()) && (operator_st.Stack_Peek().str_t[0] != operator_t[6]))
				{
					if (Priority(expression[i]) <= Priority(operator_st.Stack_Peek().str_t[0]))
					{
						std::string tmp_2 = operator_st.Stack_Pop().str_t;
						_RPN.Stack_Push(tmp_2, 1);
					}
					else
					{
						break;
					}
				}

				operator_st.Stack_Push(std::string(1, expression[i]), 1);
			}
		}
		else 
		{
			if (!(('0' <= expression[i]) && (expression[i] <= '9') || (expression[i] == operator_t[5])))
			{
				operand_t.Flag_Check = -1;
			}

			operand_t.str_t.append(1, expression[i]);
		}
	}

	if (!operand_t.str_t.empty())
	{
		_RPN.Stack_Push(operand_t.str_t, operand_t.Flag_Check);
	}

	while (!operator_st.Is_Empty())
	{
		std::string _tmp = operator_st.Stack_Pop().str_t;
		_RPN.Stack_Push(_tmp, 1);
	}
}

template <class Data_Type, class OPERATOR>
Data_Type Operation(Data_Type First_Term, Data_Type Second_Term, OPERATOR _operator)
{
	return _operator(First_Term, Second_Term);
};

template <class Data_Type, class OPERATOR>
Data_Type Operation(Data_Type First_Term, OPERATOR _operator)
{
	return _operator(First_Term);
};

template <class Data_Type>
Data_Type Add(const Data_Type First_Term, const Data_Type Second_Termb)
{
	return (First_Term + Second_Termb);
};

template <class Data_Type>
Data_Type Except(const Data_Type First_Term, const Data_Type Second_Term)
{
	return (First_Term - Second_Term);
};

template <class Data_Type>
Data_Type Multiple(const Data_Type First_Term, const Data_Type Second_Term)
{
	return (First_Term * Second_Term);
};

template <class Data_Type>
Data_Type Divide(const Data_Type First_Term, const Data_Type Second_Term)
{
	try
	{
		if (Second_Term == 0)
		{
			throw Divide_To_Zero();
		}
		else
		{
			return (First_Term / Second_Term);
		}
	}
	catch (const Divide_To_Zero& exception)
	{
		std::cout << exception.what();
		exit(FAIL_CALCULATE);
	}


};

template <class Data_Type>
Data_Type Factorial(const Data_Type _Term)
{
	try
	{
		if (_Term < 0)
		{
			throw Less_Than_Zero();
		}
		else
		{
			if (_Term < 1)  return 1;
			else			return _Term * ((_Term > 0) ? Factorial(_Term - 1) : 1);
		}
	}
	catch (const Less_Than_Zero& exception)
	{
		std::cout << exception.what();
		exit(FAIL_CALCULATE);
	}
};

template <class Data_Type>
Data_Type Exponential(const Data_Type First_Term, const Data_Type Second_Term)
{
	return pow(First_Term, Second_Term);
};

/// <summary>
/// Calculates expression.
/// </summary>
/// <param name="_RPN">Stack input.</param>
/// <returns>Result</returns>
double Calculate_RPN(Stack<Node>& _RPN)
{
	Stack<double>	Number_st;
	Stack<Node>		New_RPN_st;

	while (!(_RPN.Is_Empty()))
	{
		New_RPN_st.Stack_Push(_RPN.Stack_Peek().str_t, _RPN.Stack_Peek().Flag_Check);
		_RPN.Stack_Pop();
	}

	while (!New_RPN_st.Is_Empty())
	{
		if (New_RPN_st.Stack_Peek().Flag_Check == 0)
		{
			Number_st.Stack_Push(atof(New_RPN_st.Stack_Pop().str_t.c_str()));
		}
		else if (New_RPN_st.Stack_Peek().Flag_Check == 1)
		{
			switch (New_RPN_st.Stack_Pop().str_t[0])
			{
				case '-' : 
				{
					Number_st.Stack_Push(Operation(Number_st.Stack_Pop(), Number_st.Stack_Pop(), Except<double>));
					break;
				};

				case '+' : 
				{
					Number_st.Stack_Push(Operation(Number_st.Stack_Pop(), Number_st.Stack_Pop(), Add<double>));
					break;
				};

				case '*' : 
				{
					Number_st.Stack_Push(Operation(Number_st.Stack_Pop(), Number_st.Stack_Pop(), Multiple<double>));
					break;
				};

				case '/' : 
				{
					Number_st.Stack_Push(Operation(Number_st.Stack_Pop(), Number_st.Stack_Pop(), Divide<double>));
					break;
				};

				case '^' : 
				{
					Number_st.Stack_Push(Operation(Number_st.Stack_Pop(), Number_st.Stack_Pop(), Exponential<double>));
					break;
				};

				case '!' : 
				{
					Number_st.Stack_Push(Operation(Number_st.Stack_Pop(), Factorial<double>));
					break;
				};
			}
		}
		else if (New_RPN_st.Stack_Peek().Flag_Check == -1) 
		{
			std::cout << "Enter value of " << New_RPN_st.Stack_Pop().str_t << " = ";
			double value_temp;
			std::cin >> value_temp;
			Number_st.Stack_Push(value_temp);
		}
	}

	return Number_st.Stack_Pop();			// return result final
}

double Calculate_Expression_Value(std::string expression)
{
	Stack<Node> _RPN;
	Reserve_Polish_Notation(expression, _RPN);
	return Calculate_RPN(_RPN);
}

#endif // _RPN_H_